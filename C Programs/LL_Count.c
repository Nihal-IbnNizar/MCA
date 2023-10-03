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

void count(){
	struct node *t;
	int count=0;
	if(head==NULL){
		printf("LINKED LIST IS EMPTY!!\n");
	}
	else{
		t=head;
		while(t!=NULL){
			t=t->next;
			count++;
		}
		printf("Number of elements in the list= %d",count);
	}
    //printf("Number of elements in the list= %d",count);
}

int menu(){
    int ch;
    printf("\n-----MAIN MENU-----\n");
    printf("Insertion-1\nDisplay-2\nCount-3\nExit-4\nENTER YOUR CHOICE: ");
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
               display();
               break;
            case 3:
                count();
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