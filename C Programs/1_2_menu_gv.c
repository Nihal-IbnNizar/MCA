#include <stdio.h>
int a[5],pos=-1;

void insert()
{
    int n;
    if(pos+1==5)
    {
        printf("ARRAY IS FULL!\n");
    }
    else
    {
        printf("Enter the number:");
        scanf("%d",&n);
        printf("Inserting number %d \n",a[++pos]=n);
    }
}
void delet()
{
    if(pos==-1)
    {
        printf("ARRAY IS EMPTY!");
    }
    else
    {
        printf("Deleted element %d\n",a[pos--]);
    }
}
void sort()
{
    int i,j,temp;
    if(pos==-1)
    {
        printf("NO ELEMENTS PRESENT IN ARRAY!");
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

    printf("\n ARRAY IS SORTED!\n");

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
void search()
{
    int s,i,flag=0;
    printf("Enter the element to search:");
    scanf("%d",&s);

    for(i=0;i<pos;i++)
    {
        if(a[i]==s)
        {
            flag=1;
            break;
        }
    }
    if(flag=1)
       {
            printf("%d is found at a[%d]\n",s,i);
       }
    else
    {
      printf("ELEMENT NOT FOUND!");
    }
}
int menu()
{
    int op;
    printf("\n1-Insert\n 2-Delete\n 3-Sort\n 4-Search\n 5-Display\n 6-Exit\n Enter your choice:");
    scanf("%d",&op);
    return op;
}

void process()
{
    int ch;
    for(ch=menu();ch!=6;ch=menu())
    {
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delet();
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
            case 6:
                break;
            default:
                printf("WRONG CHOICE!\n");
                break;
        }
    }
}
int main()
{
    process();
    return 0;
}
