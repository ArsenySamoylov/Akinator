#pragma once

#include "ATC.h"

#include "BinaryTree.h"

using namespace tree;
typedef BinaryTree DataTree;

namespace data {

struct DataBase
    {
    const char* buffer;

    DataTree* data_tree; // pointer or not ??? this is the question

    int status = UNITIALIZED;
    };

int SetDataBase (DataBase* data_base, const char* path);

int BufferToTreeDataBase (DataTree* data_tree, const char* buffer);
int ParsingErrorMessage  (int return_value, const char* message, const char* buffer);
}