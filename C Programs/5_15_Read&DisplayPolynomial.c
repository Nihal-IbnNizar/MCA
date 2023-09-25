#include <stdio.h>

int main()
{
	int n,i;
	
	printf("Enter the number of terms in the polynomial: ");
	scanf("%d",&n);
	
	int poly[n][2];
	 //The row of this 2D array defines the no. of terms in the polynomial (as given by the user)
	 //There are two columns:
	 //The first column [0] is used to store the degree of the term, and the second column [1] is used to store the coefficient.

	//Reading the values of the poly from the user
	for (i=0; i<n; i++)
	{
		printf("Enter the degree of the term %d: ", i+1);
		scanf("%d",&poly[i][0]);
		
		printf("Enter the coefficient of the term %d: ", i+1);
		scanf("%d",&poly[i][1]);
	}
	
	//Displaying the polynomial
	printf("\nPolynomial: ");
	for(i=0; i<n; i++)
	{
		printf("%dx^%d",poly[i][1],poly[i][0]);
		
		if(i < n-1)
		{
			printf(" + ");
		}
	}
	printf("\n");

	return 0;
}
