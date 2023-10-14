#include <stdio.h>
int insert(int a[],int pos,int e)
{

	if(pos==4)
	{
		printf("ARRAY IS FULL!!");
	}
	else
	{
		a[++pos]=e;
		printf("Inserting element %d\n",a[pos]);
	}
	return pos;
	
}

int delet(int a[],int pos)
{

	if (pos==-1)
	{
		printf("ARRAY IS EMPTY!!");
	}
	else
	{
		int del,i,j;
		printf("Enter the value to be deleted: ");
		scanf("%d",&del);
		
		for (i=0;i<=pos;i++)
		{
			
			if(a[i]==del)
			{
				printf("Deleting element %d from position %d",del,i);
				for(j=i;j<pos;j++)
				{
					a[j]=a[j+1];
				}
				break;

			}
		}
		if(i>pos)
		{
			printf("ELEMENT NOT FOUND");
		}
		else
		{
			pos--;
		}		
	}
	return pos;
}

void search(int a[],int pos)
{
	int ser,i;
	printf("Enter the element to search:");
	scanf("%d",&ser);
	
	for(i=0;i<=pos;i++)
	{
		if(a[i]==ser)
		{
			printf("Element found at %d",i);
			break;
		}
	}
	if(i>pos)
	{
		printf("Element not found");
	}
}

int sort(int a[],int pos)
{
	if(pos==-1)
	{
		printf("ARRAY IS EMPTY!!");
	}
	else
	{
		int i,j,temp;
		for(i=0;i<pos;i++)
		{
			for(j=i+1;j<=pos;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;	
				}
						
			}
		}
		printf("ARRAY SORTED IN ASCENDING ORDER!!");
	}
return pos;
}

int disp(int a[],int pos)
{
	int i;
	if(pos==-1)
	{
		printf("ARRAY IS EMPTY!!");
	}
	else
	{
		for(i=0;i<=pos;i++)
		{
			printf("%d ",a[i]);
		}
	}
	
return pos;	
}
int menu()
{
	int op;
	printf("\n1-Insert\t2-Delete\t3-Sort\t4-Search\t5-Display\t6-Exit\nEnter your choice:");
	scanf("%d",&op);
	return op;
}

void process()
{
	int ch;
	int a[5];
	int pos=-1;
	int num;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d",&num);
		 		pos=insert(a,pos,num);
		 		break;
		 	case 2:
			 	pos=delet(a,pos);
				break;	
			case 3:
				pos=sort(a,pos);
				break;
			case 4:
			    search(a,pos);
				break;	
			case 5:
				pos=disp(a,pos);
				break;
			default:
				break;
		}
	}
	
}
int main()
{
	process();
	return 0;
}
