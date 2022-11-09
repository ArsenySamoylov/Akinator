#include "HtmlLog.h"

static FILE* HtmlLog = NULL;

int AddImage (const char* path)
    {
    if (!path) return EXIT_FAILURE;

    hlog("\t<img src = \"%s\"\n", path);
    hlog("<hr>\n<hr>\n");
    
    return EXIT_SUCCESS;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////
void hlog (const char* format, ...)
    {
    va_list ptr;
    va_start(ptr, format);

    // $p(HtmlLog)
    // $s(format)
    // $$
    vfprintf (HtmlLog, format, ptr);

    return;
    }

FILE* SetHtmlLog()
    {
    HtmlLog = fopen ("2HtmlMaster.html", "wb"); 
    setvbuf (HtmlLog, NULL, _IONBF, 0);
    
    fprintf (HtmlLog, "<pre>\n");
    fprintf (HtmlLog, "<h1>My dear log</h1>\n");

    atexit (CloseHtmlLog);
    
 // printf("NEXT IS EXIT\n");
 // exit(0);

    return HtmlLog; 
    }

void CloseHtmlLog()
    {
    printf ("Closing logs\n");
    
    if (!HtmlLog) return;

    printf("Real closing logs\n");

    hlog("<h1> END OF LOG</h1>\n"); 
    hlog("</pre>"); //some closing tags

    fflush(HtmlLog);
    fclose(HtmlLog);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////
