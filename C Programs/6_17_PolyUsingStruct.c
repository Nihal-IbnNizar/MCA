#include <stdio.h>

struct polynomial{
	int coefficient;
	int degree;
};

void read(struct polynomial poly[], int n){
	printf("Enter the terms \n");
	
	for(int i=0; i<n; i++){
		printf("Enter the coeffient of %d term: ",i+1);
		scanf("%d",&poly[i].coefficient);
		printf("Enter the degree of %d term: ",i+1);
		scanf("%d", &poly[i].degree);
	}
}

void disp(struct polynomial poly[], int n){
	printf("THE POLYNOMIAL IS: ");
	int i;
	
	for(int i=0; i<n; i++){
			printf("%dx^%d",poly[i].coefficient, poly[i].degree);
	
		if(i< n-1){
			printf(" + ");
		}
	}
}



int main(){
	int n;
	printf("Enter the total number of terms in the polynomial: ");
	scanf("%d",&n);
	
	struct polynomial poly[n];
	
	read(poly,n);
	
	disp(poly,n);
	
	return 0;
}
