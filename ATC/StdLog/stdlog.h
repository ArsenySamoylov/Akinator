#ifndef MY_LOG // turn off buferization? (mb add modes)
#define MY_LOG

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include "CommonEnums.h"
#include "ErrorMessages.h"

//! @note if you want to change log file name
//!          than define LOGNAME with name before including this file
//! @note if you want to show logs in console
//!          than define LOGNAME without name
#ifndef LOGNAME
#define LOGNAME "Logs/stdlog.txt"
#endif

//#include "my_colors.h" 
FILE* GetLog   ();
FILE* OpenLog  ();
void  CloseLog ();

void log (const char* format, ...);

void logerror   (int error_code, const char* format, ...);
void logerrno   (const char* format, ...);
void checkerrno (const char* format, ...);


int  LogMsgRet   (int return_value, const char* format, ...);
void LogMsgNoRet (const char* format, ...);

//! @note DetailedLog includes function name and location (line, file) 
#define dlog(format, ...) do                                                                                      \
                            {                                                                                     \
                            printf (my_log, "from %s (in line %d, file %s):\n\t", __func__, __LINE__, __FILE__);  \
                            printf (my_lof, format, __VA_ARGS__);                                                 \
                            } while (0);

//! @todo USE STD ERROR CODES FROM ERRNO
//! @note if you want to ralso write message, than use LogMsgRet (or NoRet) as return expression
#define assertlog(condition, error_code, return_expression) do                                                     \
                            {                                                                                      \
                            if (!condition)                                                                        \
                                {                                                                                  \
                                log("Condition (%s) is false\n", #condition);                                      \
                                log("\t(function: %s, file: %s, line: %d)\n",                                      \
                                           __func__,   __FILE__, __LINE__);                                        \
                                                                                                                   \
                                log("It matches to error: (code %d) %s\n\n", error_code, strerror(error_code));    \
                                                                                                                   \
                                return_expression;                                                                 \
                                }                                                                                  \
                                                                                                                   \
                            } while (0);

// struct SrcLocationInfo
// {
//     const char* var_name;
//     const char* src_file;
//     const char* src_function;
//     int         src_line;
// };

/* #define init_inf(name)  \
//     (SrcLocationInfo{ #name, __FILE__, __func__, __LINE__ }) 

// #define  src_loc        \
//     (SrcLocationInfo{  NULL, __FILE__, __func__, __LINE__ })
*/                                
#endif