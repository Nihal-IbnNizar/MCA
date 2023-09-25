#include <stdio.h>
#include <malloc.h>

int main(){
    int a;
    int *p;
    p=(int *) malloc(sizeof(int));
    a=20;
    *p=30;
    printf("%d %d",a,*p);

    return 0;
}
