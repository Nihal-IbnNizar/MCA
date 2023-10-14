#include<stdio.h>
int a[5],top=-1;
void push()
{
	int e;
	if(top+1==5)
	{
		printf("STACK IS FULL!!");
	}
	else
	{
		printf("Enter the element:");
		scanf("%d",&e);
		//scanf("%d",&a[++top]);    We can also insert in this way
		++top;
		a[top]=e;
	}
	
}
void pop()
{
	if(top==-1)
	{
		printf("STACK IS EMPTY!!");
	}
	else
	{
		printf("Deleted element: %d\n", a[top--]);
	}
}
void peak()
{
	printf("Element at the top is %d",a[top]);	
}
void disp()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d\t",a[i]);
	}
}
int menu()
{
	int ch;
	printf("\n1-Insert\t2-Delete\t3-Top element\t4-Display\t5-Exit\nYour Choice:");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch (ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peak();
				break;
			case 4:
				disp();
				break;
			case 5:
				break;
			default:
				printf("WRONG CHOICE!!");
				break;					
		}
	}
}
int main()
{
	process();
	return 0;
}
