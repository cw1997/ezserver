/////////////////////////
// esvr                //
// author:changwei     //
// github.com/cw1997   //
/////////////////////////
// util.c
// 2017-10-11 01:47:04

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "datetime.h"


char *getDateText()
{
	time_t timep;  
    // char s[30];  
    char *s = (char *)malloc(sizeof(char) * 32);
      
    time(&timep);  
  
    strcpy(s,ctime(&timep));  
    strtok(s, "\n");
    // Wed, 11 Oct 2017 17:12:27 GMT
    // printf("%s\n", s);
    return s;
}