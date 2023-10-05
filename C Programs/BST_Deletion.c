//Menu driven program for insertion,deletion and display.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;

tree *root=NULL;

void insert(int e){
    tree *p, *x;
    if(root==NULL){
        root=(tree *) malloc(sizeof(tree));
        root->data=e;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        p=root;
        while(p!=NULL){
            x=p;
            if(e<p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        if(e<x->data){
            x->left=(tree *) malloc(sizeof(tree));
            x->left->data=e;
            x->left->left=NULL;
            x->left->right=NULL;
        }
        else{
            x->right=(tree *) malloc(sizeof(tree));
            x->right->data=e;
            x->right->left=NULL;
            x->right->right=NULL;
        }
    }
}

void delete(int e){
    if (root == NULL) {
        return;
    }

    tree* x = NULL;
    tree* p = root;

    // Find the node to be deleted.
    while (p != NULL && p->data != e) {
        x = p;
        if (e < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    // If the node to be deleted is not found.
    if (p == NULL) {
        return;
    }

    // If the node to be deleted has no child or one child.
    if (p->left == NULL || p->right == NULL) {
        tree* child = (p->left != NULL) ? p->left : p->right;

        if (x == NULL) {
            root = child;
        } else if (x->left == p) {
            x->left = child;
        } else {
            x->right = child;
        }
    }

    // If the node to be deleted has two children.
    else {
        tree *t=p->right;
				while(t->left!=NULL)
					t=t->left;
				delete(t->data);
				p->data = t->data;
    }

}

void inorder(tree *r){        //display
    if(r!=NULL){
        inorder(r->left);
        printf("%d\t",r->data);
        inorder(r->right);
    }
}

void preorder(tree *r){
    if(r!=NULL){
        printf("%d\t",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(tree *r){
    if(r!=NULL){
        postorder(r->left);
        postorder(r->right);
        printf("%d\t",r->data);
    }
}

int menu(){
    int ch;
    printf("\n-----MAIN MENU-----");
    printf("\nInsertion-1\nDeletion-2\nDisplay-3\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return ch;
}

void disp(){
    int ch;
    printf("\n-----DISPLAY OPTIONS-----\n");
    printf("Inorder-1\nPreorder-2\nPostorder-3\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("\nInorder: ");
            inorder(root);
            break;
        case 2:
            printf("\nPreorder: ");
            preorder(root);
            break;
        case 3:
            printf("\nPostorder: ");
            postorder(root);
            break;
        default:
            menu();
    }

}

void process(){
    int ch,e;
    for(ch=menu();ch!=5;ch=menu()){
        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&e);
                insert(e);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d",&e);
                delete(e);
            case 3:
                disp();
                break;
            default:
                printf("\nInvalid Choice!");
                break;
        }
    }
}
int main(){
    process();
    return 0;
}