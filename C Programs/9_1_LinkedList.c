#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node *next;
};
struct node*head=NULL;
void insert(int e){
	struct node*t;
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

void disp(){
	struct node *t;
	if(head==NULL){
		printf("LINKED LIST IS EMPTY!!\n");
	}
	else{
		t=head;
		while(t!=NULL){
			printf("%d ",t->data);
			t=t->next;
		}
	}
}

int main(){
	disp();
	insert(100);
	insert(200);
	insert(300);
	disp();
	
	return 0;
}
