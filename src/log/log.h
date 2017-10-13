/////////////////////////
// esvr                //
// author:changwei     //
// github.com/cw1997   //
/////////////////////////
// log.h
// 2017-10-13 15:47:58

#include <stdint.h>


#ifndef LOG_LEVEL_DEBUG
#define LOG_LEVEL_DEBUG 0
#endif
#ifndef LOG_LEVEL_INFO
#define LOG_LEVEL_INFO 1
#endif
#ifndef LOG_LEVEL_NOTICE
#define LOG_LEVEL_NOTICE 2
#endif
#ifndef LOG_LEVEL_WARNING
#define LOG_LEVEL_WARNING 3
#endif
#ifndef LOG_LEVEL_ERROR
#define LOG_LEVEL_ERROR 4
#endif
#ifndef LOG_LEVEL_FATEL
#define LOG_LEVEL_FATEL 5
#endif


/*typedef enum
{
    DEBUG, 
    INFO, 
    NOTICE, 
    WARNING, 
    ERROR, 
    FATEL
} log_level_t;*/


char *getLevelText(uint8_t uiLevel);

void write_log(uint8_t uiLevel, char *sLog);
