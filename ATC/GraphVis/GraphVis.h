#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>



FILE* OpenDot (const char* path);
void  CloseDot ();


const int MAX_GRAPH_NAME_LENGTH = 40;
const int     IMAGE_NAME_LENGTH = 40;
const int SYSTEM_COMMAND_LENGTH = 155;


// mb ask programmer to write his own functions to include it here ????

const char* GetImage ();
void SetDot          ();

void SetEndDot       ();

void DotPrint     (const char* format, ...);

#define set_func_name   fprintf (Dot, "########################################################### %s\n", __func__);





//void SetNodesArr     (ArsList* list);
//void SetListStatus   (ArsList* list);

//void ConnectNodes (index_t first, index_t second);

//void PrintNode          (node* node_ptr, index_t node_num);
//void ConnectPrevAndNext (node* node_ptr, index_t node_num);