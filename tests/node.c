#include "node.h"

#include <stdlib.h>
#include <stdio.h>

Node* createNode(Element key) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

void fill_spaces(int size) {
    for (int i = 0; i < size; i++) {
        printf(" ");
    }
}

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }

    return node->height;
}

void updateHeight(Node* node) {
    if (node != NULL) {
        node->height = 1 + maximum(height(node->left), height(node->right));
    }
}

int balanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

void printDiagram(Node* node, int level) {
  if (node == NULL) {
      return;
  }
  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  element_print(node->key);
  printf(" %d %d ", height(node), balanceFactor(node));
  printf("\n");
  printDiagram(node->left, level + 1);  
  printDiagram(node->right, level + 1);
}

void nodePrint(Node* node) {
  printDiagram(node, 0);
}

void updateAllHeights(Node* root) {
    if (root != NULL) {
        updateAllHeights(root->left);
        updateAllHeights(root->right);
        updateHeight(root);
    }
}