#pragma once

enum CommandsCodes
    {
    #define CMD_DEF(cmd, num, cmd_name, code)  \
            cmd = num,
            
    #include "Commands.h"

    #undef CMD_DEF
    NOT_A_COMMAND,
    };


