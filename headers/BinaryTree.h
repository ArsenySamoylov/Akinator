#pragma once

typedef int elemen_t;

struct Node
    {
    Node*    next;
    elemen_t data;
    Node*    prev;
    };

struct Tree
    {
    Node* nodes_arr;

    int size;
    status = UNITIALIZED;
    }