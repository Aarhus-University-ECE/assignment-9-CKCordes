/*
 * Search an expression using DFS.
 */

#include "dfs.h"

#include <stdbool.h> /* bool, true, false */
#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */

void DFT(node *root) {
    if (root == NULL) {
        return;
    }

    print_node(root);

    DFT(root->lchild);

    DFT(root->rchild);
}

node *make_node(int num, node *left, node *right) {
    node *n = (node *)malloc(sizeof(node));
    n->num = num;
    n->visited = false;
    n->lchild = left;
    n->rchild = right;
    return n;
}

void free_node(node *p) {
    if (p->lchild == NULL && p->rchild == NULL) {
        free(p);
    } else if (p->lchild != NULL) {
        free(p->lchild);
    } else if (p->rchild != NULL) {
        free(p->rchild);
    }
}

void print_node(node *p) {
    if (p == NULL)
        printf("NULL\n");
    else
        printf("%d, ", p->num);
}

void print_tree(node *p, int depth) {
    for (int i = 0; i < depth; i = i + 1) printf(" ");
    printf("| ");

    if (p == NULL)
        printf("NULL\n");
    else
        printf("[%d]\n", p->num);

    if (p->lchild) {
        print_tree(p->lchild, depth + 1);
    }

    if (p->rchild) print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node) {
    stack *element = malloc(sizeof(stack));
    element->node = node;
    element->next = topp;
    return element;
}

bool isEmpty(stack *topp) {
    if (topp == NULL) {
        printf("true");
        return true;
    } else {
        printf("false");
        return false;
    }
}

node *top(stack *topp) {
    node *topNode = topp->node;
    return topNode;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp) {
    stack *temp = topp;
    topp = topp->next;
    free(temp);
    return topp;
}

void print_stack(stack *topp) {
    struct stack *temp = topp;

    while (temp != NULL) {
        print_node(temp->node);
        printf("\n");

        temp = temp->next;
    }

    printf("====\n");

    return;
}
