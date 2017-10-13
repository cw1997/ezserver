/////////////////////////
// esvr                //
// author:changwei     //
// github.com/cw1997   //
/////////////////////////
// event.h
// 2017-10-13 22:19:03

#include <stdint.h>

#ifndef EPOLL_MAX_EVENTS
#define EPOLL_MAX_EVENTS 1024
#endif
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5120
#endif

void handle_events(unsigned int uiEpollFd, struct epoll_event *stEvents, unsigned int uiReadyEventNum, unsigned int uiSockFd, char *sBuffer);

void on_accpet(unsigned int uiEpollFd, unsigned int uiSockFd);

void on_read(int uiEpollFd, unsigned int uiFd, char *psBuffer);

void on_write(int uiEpollFd, int uiFd,char *psBuffer);
