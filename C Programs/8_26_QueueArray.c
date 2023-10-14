#include <stdio.h>
#define MAX 100

int q[MAX];
int f=-1;
int r=-1;

void enqueue(){
	if(r+1==MAX){
		printf("QUEUE IS FULL!!");
	}
	else{
		if(f==-1){
			f=0;
		}
		printf("\nEnter the data: ");
		scanf("%d",&q[++r]);
	}
}

void dequeue(){
	int i;
	if(f==-1){
		printf("QUEUE IS EMPTY!!\n");
	}
	else{
		printf("Dequeued item: %d",q[f]);
		if(f==r){              //only one element
			f=r=-1;
		}
		else{                  //more than one element
			for(i=0;i<r;i++){ 
				q[i]=q[i+1];   //adjusting the index
			}
			r--;                
		}
	}
	printf("\n");
}

void disp(){
	int i;
	printf("\nTHE QUEUE IS: ");
	if(f==-1){
		printf("[NO DATA IN THE QUEUE!!]");
	}
	else{
		for(i=0;i<=r;i++){          //i<=r since r will hold the highest index value
			printf("%d\t",q[i]);
		}
	}
}

int menu()
{
	int ch;
	printf("\n-----QUEUE OPERATIONS-----");
	printf("\nEnqueue-1\nDequeue-2\nDisplay-3\nENTER YOUR CHOICE: ");
	scanf("%d",&ch);
	return ch;
}

void process()
{
	int ch;
	for (ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				disp();
				break;
			default:
				printf("\nWrong Choice.!!");
			 	break; 
			    
		}
	}
}

int main(){

	process();
	return 0;
}
