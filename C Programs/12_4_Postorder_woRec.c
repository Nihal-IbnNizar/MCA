#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;

struct stack{
    tree *r;
    int count;
    struct stack *next;
};
typedef struct stack stack;
tree *root=NULL;
stack *top=NULL;

void insert(int e){
    tree *p,*x;
    if(root==NULL){
        root=(tree *)malloc(sizeof(tree));
        root->data=e;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        p=root;
        while(p!=NULL){
            x=p;
            if(e < p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        if(e > x->data){
            x->right=(tree *)malloc(sizeof(tree));
            x->right->data=e;
            x->right->left=NULL;
            x->right->right=NULL;
        }
        else{
            x->left=(tree *)malloc(sizeof(tree));
            x->left->data=e;
            x->left->left=NULL;
            x->left->right=NULL;
        }
    }
}

void push(tree *t,int c){
    stack *temp=(stack *)malloc(sizeof(stack));
    temp->r=t;
    temp->count=c;
    temp->next=top;
    top=temp;
}
tree * pop(){
    tree *t=NULL;
    if(top!=NULL){
        t=top->r;
        top=top->next;
    }
    return t;
}
int  peek()
{
    int c = -1;
    if(top != NULL)
    {
           c = top->count;
    }
    return c;
}

void postorder_wur(tree *root){
    tree *t;
    int c;
    for(t=root;t!=NULL;t=t->left){
        push(t,1);
    }
    c=peek();
    t=pop();
    while(t!=NULL){
        if(c==1)
        {
            push(t,2);
            for(t=t->right;t!=NULL;t=t->left){
               
                push(t,1);
            }
        }
        else if (c==2)
        {
            printf("\t%d",t->data);
        }
        c=peek();
        t=pop();
    }
}
int menu(){
    int ch;
    printf("\n-----MAIN MENU-----");
    printf("\n1-INSERT.\n2-Display(Postorder)\n3-EXIT\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return ch;

}

int main(){
    int ch,e,n,i;
    for(ch=menu();ch!=3;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to insert(n) : ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                     printf("\nEnter the element to insert : ");
                     scanf("%d",&e);
                     insert(e);
                }
                break;
            case 2:
                printf("\n\nPostorder Without Using Reccursion of entered BST is : ");
                postorder_wur(root);
                break;
            case 3:
                printf("\nExiting....");
                break;
            default:
                printf("\nInvalid Input . Try again.\n");


        }
    }

    
    return 0;
}



