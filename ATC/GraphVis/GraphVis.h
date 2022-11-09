#pragma once

#include "ArsLib.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "Config.h"

#include "stdlog.h"
#include "BinaryTree.h"


using tree::BinaryTree;
using tree::Node;    

FILE* OpenDotFile  (const char* path);
void  CloseDotFile ();

void DotTreeBranch (tree::Node* node);
void PrintNode     (tree::Node* node);

// mb ask programmer to write his own functions to include it here ????

const char* MakeImg (const char* image_name);

void SetDot    ();

void SetEndDot ();

void DotPrint     (const char* format, ...);

#define set_func_name   fprintf (Dot, "########################################################### %s\n", __func__);
