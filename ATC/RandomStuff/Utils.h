#pragma once

#include <stdarg.h>
#include <stdio.h>

int MessageReturn(int return_value, const char* format, ... );

#define func_message(...)  {                              \
                            printf("\t%s: ", __func__);   \
                            printf(__VA_ARGS__);          \
                            } 

// what??  baclslash at new line warning