#include <stdio.h>
#include <malloc.h>

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
		head->next=head;
	}
	else{
		t=head;
		while(t->next!=head){
			t=t->next;
		}
		t->next=(struct node *) malloc (sizeof(struct node));
		t->next->data=e;
		t->next->next=head;
	}
}

//void disp(){
//	struct node *t;
//	if(head==NULL){
//		printf("\nCIRCULAR LINKED LIST IS EMPTY!!");
//	}
//	else{
//		t=head;
//		printf("\n");
//		while(t->next!=head){
//			printf("%d\t",t->data);
//			t=t->next;
//		}
//		printf("%d",t->data);
//	}
//}

void disp(){
	struct node *t;
	if(head==NULL){
		printf("\nCIRCULAR LINKED LIST IS EMPTY!!");
	}
	else{
		t=head;
		printf("\n");
		do{
			printf("%d\t",t->data);
			t=t->next;
		} while(t!=head);
	}
}

void delete(int e){
	struct node *t;
	if(head==NULL){
		printf("\nCIRCULAR LINKED LIST IS EMPTY!!");
	}
	else if(head->data==e && head->next==head){
		head=NULL;
	}
	else if(head->data==e){
		t=head;
		while(t->next!=head){
			t=t->next;
		}
		t->next=head->next;
		head=head->next;
	}
	else{
		t=head;
		while(t->next!=head && t->next->data!=e){
			t=t->next;
		}
		if(t->next==head){
			printf("\nELEMENT NOT FOUND!!");
		}
		else{
			t->next=t->next->next;
		}
	}
}

int menu(){
	int ch;
	printf("\n---CIRCULAR LINKED LIST OPERATIONS---\n");
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
