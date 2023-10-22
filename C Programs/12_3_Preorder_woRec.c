#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;

struct stack{
    tree *r;
    struct stack *next;
};
typedef struct stack stack;

tree *root=NULL;
stack *top=NULL;

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

void push(tree *t){
    stack *temp=(stack *) malloc(sizeof(stack));
    temp->r=t;
    temp->next=top;
    top=temp;
}

tree *pop(){
    tree *t=NULL;
    if(top!=NULL){
        t=top->r;
        top=top->next;
    }
    return t;
}
void preorder(tree *root)
{
    tree *t;
    for(t=root;t!=NULL;t=t->left)
    {
	printf("%d\t",t->data);
        push(t);
    }
    t=pop();
    while(t!= NULL)
    {
        for(t=t->right;t!=NULL;t=t->left)
        {
	    printf("%d\t",t->data);
            push(t);
        }
        t=pop();
    }
}

int menu(){
    int ch;
    printf("\n-----MAIN MENU-----");
    printf("\nInsertion-1\nDisplay (Preorder)-2\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return ch;
}
void process(){
    int ch,e;
    for(ch=menu();ch!=3;ch=menu()){
        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d",&e);
                insert(e);
                break;
            case 2:
                printf("\nPreorder: ");
                preorder(root);
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