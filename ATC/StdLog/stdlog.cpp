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

    my_log = freopen(LOGNAME, "w", stderr);    

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

    // restore stderr
    
    my_log = NULL;

    return;
    }
