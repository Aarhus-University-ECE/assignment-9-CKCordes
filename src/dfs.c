/*
 * Search an expression using DFS.
 */

#include "dfs.h"

#include <stdbool.h> /* bool, true, false */
#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */

void DFT(node *root) {
    // Initialising the stack with rooth and having it point to NULL
    stack *main = malloc(sizeof(stack));
    main->next = NULL;
    main->node = root;

    // Creating a node that has the value of root, note that we actually create
    // a node, NOT a node pointer. This is to make sure we can free the node
    // pointers in the stack
    node curr = *root;
    // if we stille have items in out stack we cant be finished visiting the
    // entire tree
    while (!isEmpty(main)) {
        // popping the top value in the stack to grab the current node
        curr = *top(main);
        main = pop(main);
        // if we have either a branch or leaf at our current nodes rchild we
        // push that node to visit it later
        if (curr.rchild != NULL) {
            main = push(main, curr.rchild);
        }
        // The same with the left side of the current node
        if (curr.lchild != NULL) {
            main = push(main, curr.lchild);
        }
        // The print the current node
        print_node(&curr);
    }

    /*
    // Recursion
    // If the current is non exisitant "pop" it in the call stack and go back
    if (root == NULL) {
        return;
    }
    // Printing the current node
    print_node(root);
    // Going all the way to the left leaf
    DFT(root->lchild);
    // Going to the right leaf
    DFT(root->rchild);*/
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
    // Allocating memory for the new element in stack
    stack *element = malloc(sizeof(stack));
    // Assigning the values to the stack element
    element->node = node;
    element->next = topp;
    // Returning the new element to the stack
    return element;
}

bool isEmpty(stack *topp) {
    // Lokal triviel
    if (topp == NULL) {
        return true;
    } else {
        return false;
    }
}

node *top(stack *topp) {
    // Lokal triviel
    node *topNode = topp->node;
    return topNode;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp) {
    // Lokal triviel

    stack *temp = topp;
    stack *newTopp = topp->next;
    free(temp);
    return newTopp;
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
