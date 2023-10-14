#include <stdio.h>
int a[5],pos=-1;

void insert(int e)
{
	if (pos+1==5)
	{
		printf("Array is full");
	}
	else
	{
		a[++pos]=e;
	}
}

void delete()
{
	if(pos==-1)
	{
		printf("ARRAY IS EMPTY!!");
	}
	else
	{
		printf("Deleted element: %d", a[pos--]);
	}
}

void search()
{
	if (pos==-1)
	{
		printf("Array is empty");
	}
	else
	{
		int i,s;
		printf("\nEnter value to be searched:");
		scanf("%d",&s);
		for(i=0;i<pos+1;i++)
		{
			if(s==a[i])
			{
				printf("\nThe  value %d is found at position %d",s,pos);
			}	
		}
	}
}

void sort()
{
    int i,j,temp;
    if(pos==-1)
    {
        printf("ARRAY IS EMPTY!!");
    }
    else
    {
    for(i=0;i<pos;i++)
    {
        for(j=0;j<pos;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("\nARRAY IS SORTED!!\n");

    }
}

void disp()
{
 int i;
 for(i=0;i<=pos;i++)
    {
        printf("%d\t",a[i]);
    }
}

int menu()
{
	int ch;
	printf("\n---MAIN MENU---");
	printf("\nInsert-1\tDelete-2\tSort-3\tSearch-4\tDisplay-5\tExit-6\nEnter Your Choice: ");
	scanf("%d",&ch);
	return ch;
}

void process()
{
	int ch;
	for (ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:
			 printf("\nEnter the element: ");
			 scanf("%d",&ch);
			 insert(ch);
			 break;
			case 2:
			 delete();
			 break;
			case 3:
			 sort();
			 break;
			case 4:
			 search();
			 break;
			case 5:
			 disp();
			 break;
			default:
			 printf("\n Wrong Choice.!");
			 break; 
			    
		}
	}
}
int main()
{
	process();
	return 0;
}
