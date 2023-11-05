#include<stdio.h>
#include<malloc.h>
struct node{
	int coe;
	int exp;
	struct node *next;
};
typedef struct node poly;
poly *head=NULL;
void insert(int c,int e){
	poly *t;
	if(head==NULL){
		head=(poly *) malloc(sizeof(poly));
		head->coe=c;
		head->exp=e;
		head->next=NULL;
	}
	else{
		t = head;
        while (t->next != NULL) {
            t = t->next;
        }
		t->next=(poly*) malloc(sizeof(poly));
		t->next->coe=c;
		t->next->exp=e;
		t->next->next=NULL;
	}
}

void disp() {
    poly* t;
    for (t = head; t != NULL; t = t->next) {
        if (t->next == NULL) {
            printf("%dx^%d", t->coe, t->exp);
        } else {
            printf("%dx^%d + ", t->coe, t->exp);
        }
    }
}

int main(){
	insert(2,3);
	insert(-3,1);
	insert(5,0);
	disp();

	return 0;
}