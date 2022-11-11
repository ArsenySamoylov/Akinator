#include "AkinatorUtils.h"

#include <assert.h>
#include "Festival.h"
#include "GraphVis.h"
#include "HtmlLog.h"
#include "my_buffer.h"

void VisualDump (DataBase* data_base)
    {
    assert (data_base);

    const char* img = MakeImg ("sample", data_base->data_tree);
    AddImage (img);

    return;
    }

int IsAnswer (const char* answer, int ans_size)
    {
    assert(answer);

    #define CMD_DEF(cmd, num, cmd_name, code)              \
            if (!strnicmp (answer, cmd_name, ans_size))    \
                return num;     
    
    #include "Commands.h"
    #undef CMD_DEF

    return NOT_A_COMMAND;
    }

void PrintCmd ()
    {
    #define CMD_DEF(cmd, num, cmd_name, code) \
             printf ("\033[9%dm%s  \033[0m", rand() % 7 + 1, cmd_name);    
    #include "Commands.h"
    #undef CMD_DEF

    printf ("\n");

    return;
    }