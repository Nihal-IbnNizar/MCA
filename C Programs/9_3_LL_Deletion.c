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
void deletebeg(){
    struct node *t;
    if(head==NULL){
        printf("\nNO ELEMENTS IN THE LIST");
    }
    else{
        printf("Deleting element: %d",head->data);
        t=head;
        head=head->next;
        free(t);
    }
}

void deleteend(){
    struct node *t;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY!!");
    }
    else if(head->next==NULL){
        printf("Deleted the only element %d",head->data);
        head=NULL;
    }
    else{
        t=head;
        while(t->next->next!=NULL){
            t=t->next;
        }
        printf("Deleting the last element %d",t->next->data);
        t->next=NULL;
    }
}
// -------------USING TWO POINTERS---------------------
//void deleteend(){
//     struct node *t, *prevnode;
//     t=head;
//     while(t->next!=NULL){
//         prevnode=t;        //stores the current value of t
//         t=t->next;         //after that we traverse and change the value of t
//     }
//     if(t==head){
//         head=NULL;
//     }
//     else{
//         prevnode->next=NULL
//     }
//     free(t);
// }

void deletespecific(int n){
    struct node *t;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY!!");
    }
    else if(head->data==n){
        printf("\nDeleting the element: %d",n);
        head=head->next;
    }
    else{
        t=head;
        while(t->next!=NULL && t->next->data!=n){
            t=t->next;
        }
        if(t->next==NULL){
            printf("\nELEMENT NOT FOUND!!");
        }
        else{
            printf("\nDeleting the element %d",n);
            t->next=t->next->next;
        }
    }

}

// -------------USING TWO POINTERS---------------------
// void deletespecific(int e)
// {
//     node *t, *prev;
//     if (head == NULL)
//     {
//         printf("Linked list is empty\n");
//     }
//     else if (head->data == e)
//     {
//         t = head;
//         head = head->next;
//         free(t);
//     }
//     else
//     {
//         t = head;
//         prev = NULL;

//         while (t != NULL && t->data !=e )
//         {
//             prev = t;
//             t = t->next;
//         }

//         if (t == NULL)
//         {
//             printf("Element not found\n");
//         }
//         else
//         {
//             prev->next = t->next;
//             free(t);
//         }
//     }
// }


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

int deletion(){
    int ch;
    printf("\n-----DELETION OPTIONS-----");
    printf("\nBeginning-1\nEnd-2\nSpecific element-3\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            deletebeg();
            break;
        case 2:
            deleteend();
            break;
        case 3:
            printf("\nEnter the element to delete: ");
            scanf("%d",&ch);
            deletespecific(ch);
            break;
        default:
            menu();
    }

}
int menu(){
    int ch;
    printf("\n-----MAIN MENU-----\n");
    printf("Insertion-1\nDeletion Options-2\nDisplay-3\nExit-4\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return(ch);
}
void process(){
    int ch;
    for(ch=menu();ch!=4;ch=menu()){
        switch (ch){
            case 1:
                insert();
                break;
            case 2:
               deletion();
               break;
            case 3:
                display();
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