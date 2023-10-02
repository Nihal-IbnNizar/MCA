#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insert(int e){
    struct node *t;
    if(head==NULL){
        head=(struct node*) malloc(sizeof(struct node));
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

void disp_rev(struct node *head){
    struct node *t=head;
    struct node *prev= NULL;
    struct node *next= NULL;

    while(t!=NULL){
        next=t->next;
        t->next=prev;
        prev=t;
        t=next;
    }
    head=prev;

    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
}
int main(){
    int i,n,e;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(i=0; i<n; i++){
        printf("Enter the element for node %d: ",i+1);
        scanf("%d",&e);
        insert(e);
    }

    printf("Linked list in reverse order: ");
    disp_rev(head);

    return 0;
}