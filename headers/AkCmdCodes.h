#pragma once

enum CommandsCodes
    {
    #define CMD_DEF(cmd, num, cmd_name, code)  \
            cmd = num,
            
    #include "Commands.h"

    #undef CMD_DEF

    YES,
    NO,
    XZ,

    NOT_A_COMMAND,
    };

// enum YesOrNoEnum
//     {
//     YES = 0,
//     NO  = 1, 
//     XZ  = 3,    
//     };