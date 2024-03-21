#ifndef AVL_TEST_H
#define AVL_TEST_H

#include "element.h"

typedef struct Node {
    Element key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

Node* createNode(Element key);
void updateHeight(Node* node);
void nodePrint(Node* node);
void updateAllHeights(Node* root);

#endif