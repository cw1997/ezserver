/////////////////////////
// esvr                //
// author:changwei     //
// github.com/cw1997   //
/////////////////////////
// util.c
// 2017-10-11 17:40:12

#include <stdint.h>

// 将str字符以spl分割,存于dst中，并返回子字符串数量
uint8_t split(char dst[][128], char* str, const char* spl);

void splitMap(char *str, char *symbol, char *key, char *value);
