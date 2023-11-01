#include<stdio.h>
#include<malloc.h>
struct node{
	int coe;
	int exp;
	struct node *next;
};
typedef struct node poly;


void insert(poly **poly1, int exp, int coe)
{
    poly *t;
    int a;
    if(*poly1 == NULL)
    {
        *poly1 = (poly *)malloc(sizeof(poly));
        *poly1->exp = exp;
        *poly1->coe = coe;
        *poly1->next = NULL;
    }
    else
    {
        t = *poly1;
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = (poly *)malloc(sizeof(poly));
        t->next->exp = exp;
        t->next->coe = coe;
        t->next->next = NULL;
    }
}

void readPoly(poly *poly)
{
	int n,i=0,coe;
	printf("Enter the degree of the polymonial : ");
	scanf("%d",&n);
	while(n>=0)
	{
		printf("Enter the coefficient of %d : ",n);
		scanf("%d",&coe);
		if(coe != 0)
		{
			insert(&poly,n,coe);
			i++;
		}
		n--;
	}
}

displayPoly()
{
	poly *t=poly1->next;
	(poly1->exp == 0) ? printf(" %d",poly1->coe) : printf(" %d^%d",poly1->coe,poly1->exp);
	while(t!=NULL)
	{
		(t->exp == 0) ? printf(" + %d",t->coe) : printf(" + %d^%d",t->coe,t->exp);
		t=t->next;
	} 
}

void main()
{
	readPoly();
	displayPoly();
	
}