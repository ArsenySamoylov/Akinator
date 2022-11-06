#pragma once

#include <errno.h>

#pragma GCC diagnostic ignored "-Wunused-value"
/*! @note Use this macros with return val (for example: CHECK_PTR_RET(ptr, return NULL_PTR)) 

#define CHECK_PTR_STDERR(ptr, return_value)                                   \
                                                {                      \
                                                if(!ptr)               \
                                                  {                    \
                                                  printf("%s common error: %s\n", __func__, COMMON_ERROR_MESSAGES[return_value]); \
                                                  return return_value; \
                                                  }                    \
                                                }
*/

/* #define CHECK_PTR_MSG(ptr, return_expression, ...)                     \
                                               {                       \
                                                if(!ptr)               \
                                                  {                    \
                                                  printf(__VA_ARGS__); \
                                                  return_expression;   \
                                                  }                    \
                                              }
*/

#define CHECK_PTRS(return_expression, ...)     {                                                          \
                                      const void* __arszsr[] = {__VA_ARGS__};                             \
                                      int number_of_pointers = sizeof(__arszsr) / sizeof(__arszsr[0]);    \
                                                                                                          \
                                      for(int i = 0; i < number_of_pointers; i++)                         \
                                        {                                                                 \
                                        if (!__arszsr[i])                                                 \
                                          {                                                               \
                                          printf("%s: !ERORR! Null pointer (number of pointer %d),\n"     \
                                                 "\t%s, from this function\n",__func__, i + 1, #return_expression);        \
                                          return_expression;                                              \
                                          }                                                               \
                                        }                                                                 \
                                      }

#define CHECK_PTR(ptr, return_expression)                                       \
                                          {                                     \
                                          if(!ptr)                              \
                                            {                                   \
                                            printf("\033[53m" "%s error: %s - NULL ptr (in line %d)\033[0m\n", __func__, __LINE__, #ptr);    \
                                            return_expression;                  \
                                            }                                   \
                                          } 

const int MAX_MESSAGE_LENGTH_FOR_STDERRR = 300;

#define CHECK_STDERR(ptr, return_expression)                                    \
                                          {                                     \
                                          if(!ptr)                              \
                                            {                                   \
                                            char      message [MAX_MESSAGE_LENGTH_FOR_STDERRR + 16]  = {}; \
                                            snprintf (message, MAX_MESSAGE_LENGTH_FOR_STDERRR, "%s error: %s - NULL ptr (in line %d)", __func__, #ptr, __LINE__); \
                                            perror   (message);                 \
                                            return_expression;                  \
                                            }                                   \
                                          }                                                   

