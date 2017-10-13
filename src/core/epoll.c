/////////////////////////
// esvr                //
// author:changwei     //
// github.com/cw1997   //
/////////////////////////
// epoll.h
// 2017-10-13 15:21:51

#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>

#include "epoll.h"

#include "event.h"
#include "socket.h"


int init_epoll(unsigned int uiFdSize)
{
    int uiEpollFd = epoll_create(uiFdSize);
    return uiEpollFd;
}

void do_epoll(unsigned int uiEpollFd, unsigned int uiSockFd)
{
    struct epoll_event stEvents[EPOLL_MAX_EVENTS];
    unsigned int uiEpollReturn;

    char sBuffer[BUFFER_SIZE];
    memset(sBuffer, 0, BUFFER_SIZE);

    add_event(uiEpollFd, uiSockFd, EPOLLIN);

    while(1)
    {
        uiReadyEventNum = epoll_wait(uiEpollFd, stEvents, EPOLL_MAX_EVENTS, -1); // return the number of the events which ready to handle
        handle_events(uiEpollFd, stEvents, uiReadyEventNum, uiSockFd, sBuffer);
    }
}

void close_epoll(unsigned int uiEpollFd)
{
    close(uiEpollFd);
}

int add_event(unsigned int uiEpollFd, unsigned int uiFd, unsigned int uiState)
{
    struct epoll_event stEvents;
    stEvents.events = uiState;
    stEvents.data.fd = uiFd;
    return epoll_ctl(uiEpollFd, EPOLL_CTL_ADD, uiFd,&stEvents);
}

int delete_event(unsigned int uiEpollFd, unsigned int uiFd, unsigned int uiState)
{
    struct epoll_event stEvents;
    stEvents.events = uiState;
    stEvents.data.fd = uiFd;
    return epoll_ctl(uiEpollFd, EPOLL_CTL_DEL, uiFd,&stEvents);
}

int modify_event(unsigned int uiEpollFd, unsigned int uiFd, unsigned int uiState)
{
    struct epoll_event stEvents;
    stEvents.events = uiState;
    stEvents.data.fd = uiFd;
    return epoll_ctl(uiEpollFd, EPOLL_CTL_MOD, uiFd,&stEvents);
}
