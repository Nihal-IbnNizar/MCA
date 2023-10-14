#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head= NULL;

void insert(int e){
    struct node *t;
    if(head==NULL){
        head=(struct node *)malloc(sizeof(struct node));
        head->data=e;
        head->next=NULL;
        head->prev=NULL;
    }
    else{
        t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=(struct node *) malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=NULL;
        t->next->prev=t;
    }
}

void disp(){
	struct node *t;
	if(head==NULL){
		printf("\nDOUBLY LINKED LIST IS EMPTY!!");
	}
	else{
		t=head;
		printf("\n");
		while(t!=NULL){
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}

void delete(int e){
    struct node *t;
    if(head==NULL){
        printf("\nDOUBLY LINKED LIST IS EMPTY!!");
    }
    else if(head->data==e && head->next==NULL){
        head=NULL;
    }
    else if(head->data==e){
        head=head->next;
        head->prev=NULL;
    }
    else{
        t=head->next;
        while(t!=NULL && t->data!=e){
            t=t->next;
        }
        if(t==NULL){
            printf("\nELEMENT NOT FOUND!!");
        }
        else if(t->next==NULL){
            t->prev->next=NULL;
        }
        else{
            t->prev->next=t->next;
            t->next->prev=t->prev;
        }
    }
}
int menu(){
	int ch;
	printf("\n---DOUBLY LINKED LIST OPERATIONS---\n");
	printf("1-Insert\n2-Delete\n3-Display\nENTER YOUR CHOICE: ");
	scanf("%d",&ch);
	
	return ch;
}

void process(){
	int ch,a;
	for(ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1:
				printf("\nEnter the element to insert: ");
				scanf("%d",&a);
				insert(a);
				break;
			case 2:
				printf("\nEnter the element to delete: ");
				scanf("%d",&a);
				delete(a);
				break;
			case 3:
				disp();
				break;
			default:
				printf("\nWRONG CHOICE!!");
				break;
		}
	}
}

int main(){
	process();
	return 0;
}