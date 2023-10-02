#include <stdio.h>
#include <malloc.h>

int main(){
    int *p,n,i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    p=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        printf("Enter p[%d]: ",i);
        scanf("%d",p+i);        
    }
    for(i=0;i<n;i++){
        printf("%d\t",*(p+i));
    }

    return 0;
}