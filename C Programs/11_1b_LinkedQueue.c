#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node queue;
enum op {ENQUEUE=1,DEQUEUE,EXIT};
queue*f=NULL, *r=NULL;

void enqueue(int e){
    queue *t;
    t=(queue *) malloc(sizeof(queue));
    t->data=e;
    t->next=NULL;
    if(f==NULL){
        f=t;
        r=t;
    }
    else{
        r->next=t;
        r=t;
    }
}

void dequeue(){
    if(f==NULL){
        printf("QUEUE IS EMPTY!!\n");
    }
    else{
        printf("Dequeued element: %d\n",f->data);
        f=f->next;
        if(f==NULL){                      //after dequeuing,if the queue becomes empty
            r=NULL;
        }
    }
}

int menu(){
    int ch;
    printf("\n-----QUEUE OPERATIONS-----");
    printf("\nEnqueue-1\nDequeue-2\nExit-3\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return ch;
}

void process(){
    int ch;
    for(ch=menu();ch!=3;ch=menu()){
        switch(ch){
            case ENQUEUE:
                printf("Enter the element to enqueue: ");
                scanf("%d",&ch);
                enqueue(ch);
                break;
            case DEQUEUE:
                dequeue();
                break;
        }
    }
}

int main(){
    process();
    return 0;
}