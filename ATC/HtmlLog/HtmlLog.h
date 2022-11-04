#pragma once

#include <stdlib.h>

void  CloseHtmlLog ();
FILE* SetHtmlLog   ();


extern FILE* HtmlLog;

void hlog (const char* format, ...);
