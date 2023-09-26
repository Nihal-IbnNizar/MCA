#include <stdio.h>
#include <malloc.h>
void read(int *p,int n)
{
    int i;
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",p+i);
    }
}
void mode(int *p,int n)
{
   int large=0, i,j,k=0, count=1;
   int a[10];
   for (i=0;i<n;i++) 
   {
     count=1;
      for (j=i+1;j<=n; j++)
      {
         if (*(p+j) == *(p+i))
            count++;
      }
      if (count >= large)
      {
         if (count > large)
            k=0;
         a[k] = *(p+i);
         large = count;
         k++;
      }
   }
    if(k==1)
        printf("The mode is %d",a[0]);
    else
    {
        printf("The modes are : ");
        for(i=0;i<k;i++)
            printf("%d\t",a[i]);
    }
}
void main()
{
    int i,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *p= (int *) calloc(n,sizeof(int));
    read(p,n);
    mode(p,n);
}