#include <stdio.h>
#include <stdlib.h>

struct books{
    char book_name[100];
    char author_name[100];
};

void read(struct books*b, int n){
    int i;
    printf("-----ENTER THE DETAILS OF BOOKS-----\n");
    for (i=0;i<n;i++){
        printf("BOOK %d\n",i+1);
        printf("Enter the name of the book: \n");
        scanf("%s",b[i].book_name);
        printf("Enter the name of the author: \n");
        scanf("%s",b[i].author_name);
    }
}

void disp(struct books*b, int n){
    int i;
    printf(">>>>> DETAILS OF THE BOOKS <<<<<\n");
    for (i=0;i<n;i++){
        printf("BOOK %d\n",i+1);
        printf("BOOK NAME: %s\n",b[i].book_name);
        printf("AUTHOR: %s\n",b[i].author_name);
    }
}

int main(){
    int n;
    printf("Enter the number of books: ");
    scanf("%d",&n);

    struct books *b;
    b=(struct books *)malloc (sizeof(struct books)*n);

    read(b,n);
    disp(b,n);

    free(b);

    return 0;

}