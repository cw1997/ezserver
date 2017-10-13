/////////////////////////
// esvr                //
// author:changwei     //
// github.com/cw1997   //
/////////////////////////
// event.h
// 2017-10-13 15:19:33

#include <stdlib.h>
#include <stddef.h>
#include <sys/epoll.h>

#include "epoll.h"
#include "../write_log/write_log.h"
#include "socket.h"


void handle_events(unsigned int uiEpollFd, struct epoll_event *stEvents, unsigned int uiReadyEventNum, unsigned int uiSockFd, char *sBuffer)
{
    unsigned int uiFd;
    for (unsigned int i = 0; i < uiReadyEventNum; ++i)
    {
        uiFd = stEvents[i].data.fd;
        // handle by stEvents[i].stEvents
        if ( (uiFd == uiSockFd) && (stEvents[i].events & EPOLLIN) ) {
            on_accpet(uiEpollFd, uiSockFd);
        } else if (stEvents[i].stEvents & EPOLLIN) {
            on_read(uiEpollFd, uiFd, sBuffer);
        } else if (stEvents[i].stEvents & EPOLLOUT) {
            on_write(uiEpollFd, uiFd, sBuffer);
        }
    }
}

void on_accpet(unsigned int uiEpollFd, unsigned int uiSockFd)
{
    unsigned int uiConnFd = handle_accpet(uiSockFd);
    if (uiConnFd != -1) {
        add_event(uiEpollFd, uiConnFd, EPOLLIN);
    }
}

void on_read(int uiEpollFd, unsigned int uiFd, char *psBuffer)
{
    size_t uiReadSize = read(uiFd, psBuffer, BUFFER_SIZE);
    if (uiReadSize == -1) {
        write_log(LOG_LEVEL_ERROR, sprintf("read error. fd : %d .", uiFd));
        close(uiFd);
        delete_event(uiEpollFd, uiFd, EPOLLIN);
    } else if (uiReadSize == 0) {
        write_log(LOG_LEVEL_INFO, sprintf("client close. fd : %d .", uiFd));
        close(uiFd);
        delete_event(uiEpollFd, uiFd,EPOLLIN);
    } else {
        write_log(LOG_LEVEL_INFO, sprintf("read success. fd : %d , read message size is : %d .", uiFd, strlen(psBuffer)));
        handle_read(uiFd, psBuffer);
        // when read message, modify this fd's event to EPOLLOUT
        modify_event(uiEpollFd, uiFd, EPOLLOUT);
    }
}

void on_write(int uiEpollFd, int uiFd,char *psBuffer)
{
    size_t uiWriteSize = write(uiFd, psBuffer, strlen(psBuffer));
    if (uiWriteSize == -1) {
        write_log(LOG_LEVEL_ERROR, sprintf("write error. fd : %d .", uiFd));
        close(uiFd);
        delete_event(uiEpollFd, uiFd, EPOLLOUT);
    } else {
        write_log(LOG_LEVEL_INFO, sprintf("write success. fd : %d , write message size is : %d .", uiFd, strlen(psBuffer)));
        modify_event(uiEpollFd, uiFd, EPOLLIN);
    }
    memset(psBuffer, 0, MAXSIZE);
}
