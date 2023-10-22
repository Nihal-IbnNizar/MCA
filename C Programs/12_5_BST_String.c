#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[100];
    struct node *left;
    struct node *right;
};
typedef struct node tree;

tree *root = NULL;

void insert(char e[100]) {
    tree *p, *x;
    if (root == NULL) {
        root = (tree *)malloc(sizeof(tree));
        strcpy(root->data, e);
        root->left = NULL;
        root->right = NULL;
    } else {
        p = root;
        while (p != NULL) {
            x = p;
            if (strcmp(p->data, e) > 0)
                p = p->left;
            else
                p = p->right;
        }
        if (strcmp(x->data, e) < 0) {
            x->right = (tree *)malloc(sizeof(tree));
            strcpy(x->right->data, e);
            x->right->left = NULL;
            x->right->right = NULL;
        } else {
            x->left = (tree *)malloc(sizeof(tree));
            strcpy(x->left->data, e);
            x->left->left = NULL;
            x->left->right = NULL;
        }
    }
}

void inorder(tree *r) {
    if (r != NULL) {
        inorder(r->left);
        printf("%s\t", r->data);
        inorder(r->right);
    }
}

int menu() {
    int ch;
    printf("\n-----MAIN MENU-----");
    printf("\nInsertion-1\nDisplay-2\nENTER YOUR CHOICE: ");
    scanf("%d", &ch);
    return ch;
}

void process() {
    int ch;
    char e[100];
    for (ch = menu(); ch != 3; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the string: ");
                scanf("%s", e);
                insert(e);
                break;
            case 2:
                printf("\nString in Inorder: \n");
                inorder(root);
                break;
            default:
                printf("\nInvalid Choice!");
                break;
        }
    }
}

int main() {
    process();
    return 0;
}
