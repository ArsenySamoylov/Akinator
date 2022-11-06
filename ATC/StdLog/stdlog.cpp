#include "stdlog.h"

static FILE* my_log = NULL; 

FILE* GetLog()
    {
    return my_log;
    }

FILE* OpenLog()     
    {
    if (!LOGNAME)
        return stdout;

    //my_log = freopen(LOGNAME, "w", stderr);   
    my_log = fopen (LOGNAME, "w"); 

    if (!my_log)
        {
        perror("CAN'T OPEN LOG FILE\n"); 
        return  NULL; 
        }
        

    setvbuf(my_log, NULL, _IONBF, 0);

    atexit(CloseLog);

    return my_log;  
    }

void log (const char* format, ...)
    {
    va_list ptr;
    va_start(ptr, format);

    vfprintf (my_log, format, ptr);

    return;
    }
void CloseLog()
    {
    long NewYorkTime = time (NULL);

    log("*********************************************************************\n");
    log("\t\tLog Successfuly ended, on %s", ctime(&NewYorkTime));
    log("*********************************************************************\n");

    fclose(my_log);    
    my_log = NULL;

    return;
    }

int LogMsgRet(int return_value, const char* format, ... )
    {
    va_list ptr;
    va_start(ptr, format);

    vfprintf (my_log, format, ptr);

    return return_value;
    }

void LogMsgNoRet(const char* format, ... )
    {
    va_list ptr;
    va_start(ptr, format);

    vfprintf (my_log, format, ptr);

    return;
    }

void logerror (int error_code, const char* format, ...)
    {
    va_list ptr;
    va_start(ptr, format);

    vfprintf (my_log, format, ptr);

    log("\n\terror: (code %d) %s\n\n", error_code, strerror(error_code));                
                                                          
    return;
    }

void logerrno (const char* format, ...)
    {
    va_list ptr;
    va_start(ptr, format);

    vfprintf (my_log, format, ptr);

    log("\n\terror: (code %d) %s\n\n", errno, strerror(errno));                
                                                          
    return;
    }

void checkerrno (const char* format, ...)
    {
    if (errno)
        {
        va_list ptr;
        va_start(ptr, format);

        vfprintf (my_log, format, ptr);

        log("\n\terror: (code %d) %s\n\n", errno, strerror(errno));                
        } 
    else
        {
        log("Everything fine\n\n");
        }  

    return;
    }

