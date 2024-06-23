#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node NODE;
typedef struct node* NODE_PTR;

void TR_init(NODE_PTR* root) {
    *root = NULL;
}

int TR_empty(NODE_PTR root) {
    return root == NULL;
}

int TR_data(NODE_PTR p) {
    return p->data;
}

void TR_insert_root(NODE_PTR* root, int x) {
    if (*root != NULL) {
        exit(1);
    }

    NODE_PTR newnode = (NODE_PTR)malloc(sizeof(NODE));
    if (!newnode) {
        puts("Memory allocation failed!");
        exit(1);
    }

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    *root = newnode;
}

void TR_insert_left(NODE_PTR node, int x) {
    if (node->left != NULL) {
        exit(1);
    }

    NODE_PTR newnode = (NODE_PTR)malloc(sizeof(NODE));
    if (!newnode) {
        puts("Memory allocation failed!");
        exit(1);
    }

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    node->left = newnode;
}

void TR_insert_right(NODE_PTR node, int x) {
    if (node->right != NULL) {
        exit(1);
    }

    NODE_PTR newnode = (NODE_PTR)malloc(sizeof(NODE));
    if (!newnode) {
        puts("Memory allocation failed!");
        exit(1);
    }

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    node->right = newnode;
}

void TR_delete_root(NODE_PTR* root, int* x) {
    if ((*root)->left != NULL || (*root)->right != NULL) {
        exit(1);
    }

    *x = (*root)->data;
    free(*root);
    *root = NULL;
}

void TR_delete_left(NODE_PTR parent, int* x) {
    if (parent->left == NULL) {
        exit(1);
    }

    NODE_PTR current = parent->left;
    *x = current->data;
    free(current);
    parent->left = NULL;
}

void TR_delete_right(NODE_PTR parent, int* x) {
    if (parent->right == NULL) {
        exit(1);
    }

    NODE_PTR current = parent->right;
    *x = current->data;
    free(current);
    parent->right = NULL;
}

void TR_printnode(NODE_PTR p) {
    printf(" %d ", p->data);
}

void TR_preorder(NODE_PTR v) {
    if (v) {
        TR_printnode(v);
        TR_preorder(v->left);
        TR_preorder(v->right);
    }
}

void TR_inorder(NODE_PTR v) {
    if (v) {
        TR_inorder(v->left);
        TR_printnode(v);
        TR_inorder(v->right);
    }
}



int main(void) {
    int x;
    NODE_PTR root;
    TR_init(&root);
    TR_insert_root(&root, 10);
    TR_insert_left(root, 6);
    TR_insert_right(root, 14);
    TR_insert_left(root->left, 5);
    TR_insert_right(root->left, 7);

    printf("\nPreorder traversal:");
    TR_preorder(root);
    printf("\n");

    return 0;
}
