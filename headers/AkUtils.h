#pragma once

#include "AkCmdCodes.h"
#include "DataBase.h"

const int  ANSWER_LNGT      = 10;

int  IsAnswer  (const char* answer, int ans_size);
int  IsYesOrNo (const char* text  , int text_size);

void PrintCmd  ();
int  GetAnswer ();

void VisualDump (DataBase* data_base);
