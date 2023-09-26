#include <stdio.h> 
#include <malloc.h>

int main(){
    int n,i,*p1,*p2;
    printf("Enter the value for n (no. of mem locations): ");
    scanf("%d",&n);

    p1=(int *) malloc(sizeof(int)*n);
    p2=(int *) calloc(n,sizeof(int));

    if(p1!=NULL){
        printf("malloc is succesfull!!");
        for(i=0; i<n; i++){
            printf("\nEnter the values: ");
            scanf("%d",p1+i);    
        }
        printf("\nEntered values are:");
        for(i=0; i<n; i++){
            printf("%d\t",*(p1+i));
        }
    }
    else{
        printf("\nmalloc is failed!!");
    }

    if(p2!=NULL){
        printf("\ncalloc is succesfull!!");
        for(i=0; i<n; i++){
            printf("\nEnter the values: ");
            scanf("%d",p2+i);    
        }
        printf("\nEntered values are:");
        for(i=0; i<n; i++){
            printf("%d\t",*(p2+i));
        }
    }
    else{
            printf("\ncalloc is failed!!");
        }

    return 0;        
}