#pragma once

const int CRINGE = 0xDED;

enum ObjectStatus
    {
    UNITIALIZED = -1,
    ACTIVE      =  0, 
    DEAD        =  1,
    };

enum ReturnStatus
    {
    SUCCESS = 0,
    FAILURE = -1, 
    };

enum ArgumentsErrors
    {
    NO_ARGUMENTS                = 1,
    WRONG_ARGUMENT              = 3, 
    WROMG_NUMBER_OF_ARGUMENTS   = 4,
    };

enum FILEerrors
    {
    ERROR_OPENING_FILE = 5,
    ERROR_READING_FILE = 6,
    };

enum DynamicMemoryErrors
    {    
    BAD_CALLOC             = 7,
    BAD_REALLOC            = 8,
    };

enum CommonErrors
    {
    NULL_PTR               = 9,
    NULL_STRUCTURE_MEMBER  = 10,

    SYNTAX_ERROR           = 11,  
    };
