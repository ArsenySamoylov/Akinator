#pragma once

#include "BinaryTree.h"

//typedef BinaryTree DataTree;

struct DataBase
    {
    const char* buffer;

    BinaryTree* data_tree; // pointer or not ??? this is the question

    int status; // = UNITIALIZED;
    };

int SetDataBase (DataBase* data_base, const char* path);

int BufferToTreeDataBase (BinaryTree* data_tree, const char* buffer);
int ParsingErrorMessage  (int return_value, const char* message, const char* buffer);