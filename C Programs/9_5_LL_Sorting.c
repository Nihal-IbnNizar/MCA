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

void sort_values(){
	struct node *i,*j;
	int temp;
	
	if(head==NULL){
		printf("LINKED LIST IS EMPTY!!");
	}
	else{
		for(i=head;i!=NULL;i=i->next){
			for(j=i;j->next!=NULL;j=j->next){
				if(i->data > j->data){
					temp=i->data;
					i->data=j->data;
					j->data=temp;
				}
			}
		}
		printf("\nLINKED LIST SORTED SUCCESSFULLY!!");
	}
}

//void sort_address(){
//	
//}

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

int sort(){
    int ch;
    printf("\n-----SORTING OPTIONS-----");
    printf("\nBy Swapping Values-1\nBy Swapping Address-2\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            sort_values();
            break;
//        case 2:
//            sort_address();
//            break;
        default:
            menu();
    }
}

int menu(){
    int ch;
    printf("\n-----MAIN MENU-----\n");
    printf("Insertion-1\nSort-2\nDisplay-3\nExit-4\nENTER YOUR CHOICE: ");
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
               sort();
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
