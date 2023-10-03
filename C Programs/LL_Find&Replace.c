#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;

void insert(){
    struct node *t;
    int e;
    printf("Enter the element to insert: ");
    scanf("%d",&e);

    if(head==NULL){
        head=(struct node *) malloc(sizeof(struct node));
        head->data=e;
        head->next=NULL;
    }
    else{
        t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=(struct node *) malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=NULL;
    }
}

void display(){
    struct node *t;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY!!");
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

void replace(int r){
    struct node *t;
    int e;
    printf("Enter the new data: ");
    scanf("%d",&e);
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY!!");
    }
    else{
        t=head;
        while(t!=NULL && t->data!=r){
            t=t->next;
        }
        if(t==NULL){
            printf("Element not found\n");
        }
        else{
            t->data=e;
        }
    }
}

int menu(){
    int ch;
    printf("\n-----MAIN MENU-----\n");
    printf("Insertion-1\nDisplay-2\nFind & Replace-3\nExit-4\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return(ch);
}
void process(){
    int ch,r;
    for(ch=menu();ch!=4;ch=menu()){
        switch (ch){
            case 1:
                insert();
                break;
            case 2:
               display();
               break;
            case 3:
                printf("Enter the element to replace: ");
                scanf("%d",&r);
                replace(r);
                break;
            default:
                printf("INVALID CHOICE!!");
                break;
        }
    }
}
int main(){
    process();
    return 0;
}