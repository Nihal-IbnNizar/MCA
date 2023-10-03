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

void search(int e){
    struct node *t;
    int found=0;
    if(head==NULL){
        printf("\nLINKED LIST IS EMPTY!!");
    }
    else{
        t=head;
        while(t!=NULL){
            if(t->data==e){
                //printf("Element found in the list!!");
                found=1;
                break;
            }
            t=t->next;
        }
        if(found){
        	printf("Element found in the list!!");
		}
		else{
			printf("Element not found in the list!!");

		}
    }
}

int menu(){
    int ch;
    printf("\n-----MAIN MENU-----\n");
    printf("Insertion-1\nDisplay-2\nSearch-3\nExit-4\nENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return(ch);
}
void process(){
    int ch,e;
    for(ch=menu();ch!=4;ch=menu()){
        switch (ch){
            case 1:
                insert();
                break;
            case 2:
               display();
               break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d",&e);
                search(e);
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