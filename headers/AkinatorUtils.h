#pragma once

#include "config.h"
#include "DataBase.h"
 
int  IsAnswer (const char* answer, int ans_size);
void PrintCmd ();

void VisualDump (DataBase* data_base);