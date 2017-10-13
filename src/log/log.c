/////////////////////////
// esvr                //
// author:changwei     //
// github.com/cw1997   //
/////////////////////////
// log.c
// 2017-10-13 21:58:25

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <time.h>
#include <string.h>

#include "../datetime.h"


char *getLevelText(uint8_t uiLevel)
{
    static char arrLogLevel[][8] = {
        "DEBUG", 
        "INFO", 
        "NOTICE", 
        "WARNING", 
        "ERROR", 
        "FATEL"
    };
    // char sLogLevel[8];
    // strcpy(sLogLevel, arrLogLevel[uiLevel]);
    // return sLogLevel;
    return arrLogLevel[uiLevel];
}

/*void log(uint8_t uiLevel, char *sLog)
{
	printf("%s [%s] %s\n", getDateText(), getLevelText(uiLevel), sLog);
}*/
void write_log(uint8_t uiLevel, char *sLog)
{
    // printf("%s [%s] %s\n", "sDateTime", getLevelText(uiLevel), sLog);
	printf("%s [%s] %s\n", getDateText(), getLevelText(uiLevel), sLog);
}
