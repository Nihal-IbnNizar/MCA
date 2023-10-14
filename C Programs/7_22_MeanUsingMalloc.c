#include <stdio.h>
#include <malloc.h>

int main(){
	int n,i,*p;
	int sum=0;
	float mean;
	
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	p=(int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++){
		printf("Enter the elements: ");
		scanf("%d",p+i);
			sum=sum+ *p+i;
	}
	mean=sum/n;
	printf("The mean is: %f",mean);
	
}
