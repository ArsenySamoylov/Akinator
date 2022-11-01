#pragma once


enum ObjectStatus
    {
    UNITIALIZED,
    ACTIVE, 
    DEAD,
    };

enum CommonErrors
    {
    SUCCESS = 0,   //= 0, 
    FAILURE, 
    NO_ARGUMENTS,
    WRONG_ARGUMENT, 
    WROMG_NUMBER_OF_ARGUMENTS,

    ERROR_OPENING_FILE,
    
    BAD_CALLOC,
    BAD_REALLOC,

    NULL_PTR,
    NULL_STRUCTURE_MEMBER,

    SYNTAX_ERROR,  
    };

enum ANOTHER_COMMON_ERRORS
  {
  MAIN_SUCCESS  = 0,
  MAIN_ERROR,
  };