/**
 * Binary Search Tree implementation with AVL balancing.
*/

#include "avl.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    Element key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

struct AVL {
    Node* root;
};


AVL* avl_create() {
    AVL* bst = malloc(sizeof(AVL));

    bst->root = NULL;

    return bst;
}

void destroyRecur(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL) {
        destroyRecur(node->left);
    }
    if (node->right != NULL) {
        destroyRecur(node->right);
    }
    free(node);
}

void avl_destroy(AVL* bst) {
    destroyRecur(bst->root);
    free(bst);
}

bool searchRecur(Node* node, Element key) {
    if (node == NULL) {
        return false;
    }
    if (node->key == key) {
        return true;
    }
    if (key < node->key) {
        return searchRecur(node->left, key);
    } 
    
    return searchRecur(node->right, key);
}

bool avl_search(AVL* bst, Element key) {
    return searchRecur(bst->root, key);
}

Node* createNode(Element key) {
    Node* newNode = malloc(sizeof(Node));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

Node* insertRecur(Node* node, Element key) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insertRecur(node->left, key);
    } else if (key > node->key) {
        node->right = insertRecur(node->right, key);
    }

    return node;
}

void avl_insert(AVL* bst, Element key) {
    bst->root = insertRecur(bst->root, key);
}

Node* successor(Node* node) {
    if (node == NULL) {
        return NULL;
    }

    Node* cur = node->right;

    while (cur->left != NULL) {
        cur = cur->left;
    }

    return cur;
}

Node* removeRecur(Node* node, Element key) {
    if (node == NULL) {
        return node;
    }
    if (key < node->key) {
        node->left = removeRecur(node->left, key);
    } else if (key > node->key) {
        node->right = removeRecur(node->right, key);
    } else {
        if (node->left == NULL) {
            Node* trash = node;

            node = node->right;
            free(trash);
        } else if (node->right == NULL) {
            Node* trash = node;

            node = node->left;
            free(trash);
        } else {
            Node* temp = successor(node);

            node->key = temp->key;
            node->right = removeRecur(node->right, temp->key);
        }
    }

    return node;
}

void avl_remove(AVL* bst, Element key) {
    bst->root = removeRecur(bst->root, key);
}

void fill_spaces(int size) {
    for (int i = 0; i < size; i++) {
        printf(" ");
    }
}

void printDiagram(Node* node, int level) {
  if (node == NULL) {
      return;
  }
  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  element_print(node->key);
//   printf(",%d,%d ", height(node), balanceFactor(node));
  printf("\n");
  printDiagram(node->left, level + 1);  
  printDiagram(node->right, level + 1);
}

void avl_print(AVL* bst) {
  printDiagram(bst->root, 0);
}