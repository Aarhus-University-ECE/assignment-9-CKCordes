/*
 * Search an expression using DFS.
 */

#include "dfs.h"

#include <stdbool.h> /* bool, true, false */
#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */

void DFT(node *root) {
    // If the current is non exisitant "pop" it in the call stack and go back
    if (root == NULL) {
        return;
    }
    // Printing the current node
    print_node(root);
    // Going all the way to the left leaf
    DFT(root->lchild);
    // Going to the right leaf
    DFT(root->rchild);
}

node *make_node(int num, node *left, node *right) {
    // Allocating memory for the new node
    node *n = (node *)malloc(sizeof(node));
    // Assigning the values for the new node
    n->num = num;
    n->visited = false;
    n->lchild = left;
    n->rchild = right;
    // returning the node
    return n;
}

void free_node(node *p) {
    // Not used in the code
    // Freeing the node and all of its small branches using recursion
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
    // Not used in the code
    // Allocating memory for the new element in stack
    stack *element = malloc(sizeof(stack));
    // Assigning the values to the stack element
    element->node = node;
    element->next = topp;
    // Returning the new element to the stack
    return element;
}

bool isEmpty(stack *topp) {
    // not used in the code
    // Lokal triviel
    if (topp == NULL) {
        return true;
    } else {
        return false;
    }
}

node *top(stack *topp) {
    // Not used in the code
    // Lokal triviel
    node *topNode = topp->node;
    return topNode;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp) {
    // Not used in the code
    // Lokal triviel
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
