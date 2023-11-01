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
	int i,j,del,flag=0;

	if(pos==-1)
	{
		printf("\nARRAY IS EMPTY!!\n");
	}
	else
	{
		//printf("Deleted element: %d", a[pos--]);    We can either just end the prgrm here by deleting the last element or choose the method below.
		printf("\nEnter the element to be deleted: ");
		scanf("%d",&del);

		for(i=0;i<pos+1;i++){
			if(a[i]==del){
				flag=1;
				break;
			}
		}
		if(flag==1){
			for(j=i;j<pos;j++){
				a[j]=a[j+1];
			} 
			pos--;
			printf("Deleted element %d\n",del);
		}
		else{
			printf("Element not found in the array!!\n");
		}

	}
}

void search()  //linear search
{
	if (pos==-1)
	{
		printf("Array is empty!!");
	}
	else
	{
		int i,s,found=0;
		printf("\nEnter value to be searched:");
		scanf("%d",&s);
		for(i=0;i<pos+1;i++)
		{
			if(s==a[i])
			{
				printf("\nThe  value %d is found at position %d",s,pos);
				found=1;
				break;
			}
		}
		if(found==0)
		{
			printf("\nThe searched element is not found in the array!!\n");
		}
	}
}

void sort()
{
    int i,j,temp;
    if(pos==-1)
    {
        printf("\nARRAY IS EMPTY!!\n");
    }
    else{
    	for(i=0;i<pos;i++){
        	for(j=i+1;j<=pos;j++){
        	    if(a[i]>a[j]){
        	        temp=a[i];
    	            a[i]=a[j];
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
 printf("\nARRAY IS:-\n");
 for(i=0;i<=pos;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
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
