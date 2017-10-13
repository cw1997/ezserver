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

#include "string.h"

// 将str字符以spl分割,存于dst中，并返回子字符串数量
uint8_t split(char dst[][128], char* str, const char* spl)
{
    uint8_t n = 0;
    char *result = NULL;
    result = strtok(str, spl);
    while( result != NULL )
    {
        strcpy(dst[n++], result);
        result = strtok(NULL, spl);
    }
    return n;
}

void splitMap(char *str, char *symbol, char *key, char *value)
{
	char tmp[512];
	strcpy(tmp, str);
	char *symbolIndex = strstr(tmp, symbol); // Content-Length: 128
	stpcpy(value, tmp);
	strtok(tmp, symbol);
	strcpy(key, tmp);
	stpcpy(value, (symbolIndex + strlen(symbol)));
}
