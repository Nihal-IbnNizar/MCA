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
    printf("\nInsertion-1\nInorder-2\nPreorder-3\nPostorder-4\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return ch;
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
                printf("\nInorder: ");
                inorder(root);
                break;
            case 3:
                printf("\nPreorder: ");
                preorder(root);
                break;
            case 4:
                printf("\nPostorder: ");
                postorder(root);
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