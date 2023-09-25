#include <stdio.h>

struct employee{
	int eno;
	char ename[20];
	int esalary;
	int dno;
};

void read(struct employee e[],int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("Enter the employee number: ");
		scanf("%d",&e[i].eno);
		printf("Enter the employee name: ");
		scanf("%s",&e[i].ename);
		printf("Enter the salary: ");
		scanf("%d",&e[i].esalary);
		printf("Enter the department number: ");
		scanf("%d",&e[i].dno);
	}
}

void display(struct employee e[],int n)
{
	int i;
	printf("ENo.\tEName\tSalary\tDeptNo.");
	
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%s\t%d\t%d",e[i].eno,e[i].ename,e[i].esalary,e[i].dno);
	}
	printf("\n");
}

void sort_by_salary(struct employee e[],int n){
	int i,j;
	struct employee t;
	
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(e[i].esalary>e[j].esalary)
			{
				t=e[i];
				e[i]=e[j];
				e[j]=t;
			}
		}
	}
	
}

void sort_by_name(struct employee e[],int n){
	int i,j;
	struct employee t;
	
	for(i=0; i<n-1; i++)
	{
		for(j=i; j<n; j++)
		{
			if(strcmp (e[i].ename,e[j].ename)>0)
			{
				t=e[i];
				e[i]=e[j];
				e[j]=t;
			}
		}
	}
}

void search(struct employee e[],int n){
	int i,s;
	
	printf("Enter the employee number to search: ");
	scanf("%d",&s);
	
	for(i=0; i<n; i++)
	{
		if(e[i].eno==s)
		{
			printf("EMPLOYEE IS FOUND!");
			break;
		}
	}
	if(e[i].eno!=s)
	{
		printf("EMPLOYEE NOT FOUND!");
	}
	
}

int delete(struct employee e[],int n){
	int i,s,j;
	
	printf("Enter the employee number to delete: ");
	scanf("%d",&s);
	
	for(i=0; i<n; i++)
	{
		if(e[i].eno==s)
		{
			for(j=i; j<n-1; j++)
			{
				e[j]=e[j+1];
			}
			--n;
			printf("%d IS DELETED!",s);
			return n;
		}
	}
	printf("%d IS NOT FOUND!\n",s);
	return n;
}

int menu(){
	int ch;
	printf("\nEnter your choice:\n");
	printf("1-Display\n2-Sort by salary\n3-Sort by name\n4-Search\n5-Delete\n");
	scanf("%d",&ch);
	return ch;
}

int main()
{
	struct employee e[20];
	
	int n;
	printf("Enter the total number of employees: ");
	scanf("%d",&n);
	read(e,n);
	
	int ch;
	for(ch= menu(); ch!=6; ch=menu())
	{
		switch (ch)
		{
			case 1:
				display(e,n);
				break;
			case 2:
				sort_by_salary(e,n);
				break;
			case 3:
				sort_by_name(e,n);
				break;
			case 4:
				search(e,n);
				break;
			case 5:
				n= delete(e,n);
				break;
			default:
				printf("WRONG CHOICE!\n");
				break;			
		}
		printf("\n");
	}
}
