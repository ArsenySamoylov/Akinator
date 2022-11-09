#pragma once


#include "ArsLib.h"
#include <malloc.h>

namespace tree {

typedef char elemen_t;
const int DATA_SIZE = 256;

struct Node
    {
    Node*    parent;
    elemen_t data[DATA_SIZE] = {};

    Node*  first_child;
    Node* second_child;
    };

struct BinaryTree
    {
    Node* root;

    int size;
    int status = UNITIALIZED;
    };

int Ctor (BinaryTree* tree);
int Dtor (BinaryTree* tree);

int Add (Node* node);

}

