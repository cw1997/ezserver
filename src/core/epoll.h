/////////////////////////
// esvr                //
// author:changwei     //
// github.com/cw1997   //
/////////////////////////
// epoll.h
// 2017-10-13 15:22:30

#include <stdint.h>

#ifndef EPOLL_MAX_EVENTS
#define EPOLL_MAX_EVENTS 1024
#endif
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5120
#endif


int init_epoll(unsigned int uiFdSize);

void do_epoll(unsigned int uiEpollFd, unsigned int uiSockFd);

void close_epoll(unsigned int uiEpollFd);

int add_event(unsigned int uiEpollFd, unsigned int uiFd, unsigned int uiState);

int delete_event(unsigned int uiEpollFd, unsigned int uiFd, unsigned int uiState);

int modify_event(unsigned int uiEpollFd, unsigned int uiFd, unsigned int uiState);

