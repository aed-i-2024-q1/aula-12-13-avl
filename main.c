#include "avl.h"

#include <stdio.h>

void test_ll() {
    AVL* avl = avl_create();

    avl_insert(avl, 10);
    avl_insert(avl, 7);
    avl_insert(avl, 20);
    avl_insert(avl, 5);
    avl_insert(avl, 9);

    avl_print(avl);

    avl_insert(avl, 3);

    avl_print(avl);

    avl_destroy(avl);
}

void test_rr() {
    AVL* avl = avl_create();

    avl_insert(avl, 10);
    avl_insert(avl, 5);
    avl_insert(avl, 20);
    avl_insert(avl, 15);
    avl_insert(avl, 25);

    avl_print(avl);

    avl_insert(avl, 30);

    avl_print(avl);

    avl_destroy(avl);
}

void test_lr() {
    AVL* avl = avl_create();

    avl_insert(avl, 15);
    avl_insert(avl, 10);
    avl_insert(avl, 20);
    avl_insert(avl, 5);
    avl_insert(avl, 13);

    avl_print(avl);

    avl_insert(avl, 12);

    avl_print(avl);

    avl_destroy(avl);
}

void test_rl() {
    AVL* avl = avl_create();

    avl_insert(avl, 15);
    avl_insert(avl, 10);
    avl_insert(avl, 30);
    avl_insert(avl, 25);
    avl_insert(avl, 40);

    avl_print(avl);

    avl_insert(avl, 29);

    avl_print(avl);

    avl_destroy(avl);
}

void test_degenerate() {
    AVL* avl = avl_create();

    for (int i = 0; i < 10; i++) {
        avl_insert(avl, i + 1);
        avl_print(avl);
        printf("\n");
    }

    avl_destroy(avl);
}


int main(int argc, char const *argv[]) {
    // test_ll();
    // test_rr();
    // test_lr();
    // test_rl();
    test_degenerate();
    
    return 0;
}