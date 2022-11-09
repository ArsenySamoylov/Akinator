#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void  CloseHtmlLog ();
FILE* SetHtmlLog   ();

void hlog (const char* format, ...);

int AddImage (const char* path);
