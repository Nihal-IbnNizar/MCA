#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node stack;
stack *top=NULL;

void push(int e){
	stack *t=(stack *) malloc(sizeof(stack));
	t->data=e;
	t->next=top;
	top=t;
}

void pop(){
	if(top==NULL){
		printf("STACK IS EMPTY!!\n");
	}
	else{
		printf("Popped element: %d\n",top->data);
		top=top->next;
	}
}

void pop2(){
	if(top==NULL){						//for displaying
		printf("STACK IS EMPTY!!\n");
	}
	else{
		printf("Stack is: ");
		while(top!=NULL){
			printf("%d\t",top->data);
			top=top->next;
		}
	}
}

int menu(){
	int ch;
	printf("\n------STACK OPERATIONS-----");
	printf("\nPush-1\nPop-2\nDisplay-3\nExit-4\nENTER YOUR CHOICE: ");
	scanf("%d",&ch);
	return ch;
}

void process(){
	int ch;
	for(ch=menu();ch!=4;ch=menu()){
		switch(ch){
			case 1:
				printf("Enter the element to push: ");
				scanf("%d",&ch);
				push(ch);
				break;
			case 2:
				pop();
				break;
			case 3:
				pop2();  //displaying stack
				break;
			default:
				break;
		}
	}
}

int main(){
	process();
	return 0;
}