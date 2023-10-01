#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node*head=NULL;
void insertb(int e){
    struct node *t;
        t=(struct node*) malloc(sizeof(struct node));
        t->data=e;
        t->next=head;
        head=t;
}
void insertm(int e){
    struct node *t;
    struct node *a;
    int n;
    printf("\nEnter the element after which you want to insert: ");
    scanf("%d",&n);
    t=head;
    while(t!=NULL && t->data!=n){
        t=t->next;
    }
    if(t==NULL){
        printf("ELEMENT NOT FOUND IN THE LIST!\n");
    }
    else{
        a=(struct node*) malloc(sizeof(struct node));
        a->data=e;
        a->next=t->next;
        t->next=a;
    }
}
void inserte(int e) {
    struct node *t, *a;
    a=(struct node*) malloc(sizeof(struct node));
    a->data=e;
    a->next=NULL;
    if(head==NULL) {
        head=a;
    } 
    else{
        t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=a;
    }
}
void disp(){
    struct node*t;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY");
    }
    else{
        t=head;
        printf("\nLINKED LIST IS: \n");
        while(t!=NULL){
            printf("%d\t",t->data);
            t=t->next;
        }
    }
}
int menu(){
    int ch;
    printf("\n-----MAIN MENU-----");
    printf("\nInsertion Options-1\nDisplay-2\nExit-3\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return ch;
}

int insertion(){
    int ch;
    printf("\n-----INSERTION OPTIONS-----");
    printf("\nBeginning-1\nMiddle-2\nEnd-3\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("\nEnter the element to insert: ");
            scanf("%d",&ch);
            insertb(ch);
            break;
        case 2:
            printf("\nEnter the element to insert: ");
            scanf("%d",&ch);
            insertm(ch);
            break;
        case 3:
            printf("\nEnter the element to insert: ");
            scanf("%d",&ch);
            inserte(ch);
            break;
        default:
            menu();
    }
}
void process(){
    int ch;
    for(ch=menu();ch!=3;ch=menu()){
        switch(ch){
            case 1:
                insertion();
                break;
            case 2:
                disp();
                break;
            default:
                printf("\nINVALID CHOICE!!");
        }
    }
}
int main(){
    process();
    return 0;
}