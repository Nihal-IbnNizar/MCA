#include <stdio.h>

int main()
{
	int n1,n2,i,j,k;
	
	printf("Enter the number of terms in the first polynomial: ");
	scanf("%d",&n1);
	
	printf("Enter the number of terms in the second polynomial: ");
	scanf("%d",&n2);
	
	int poly1[n1][2], poly2[n2][2], result[n1+n2][2];
	
	printf("---ENTER THE TERMS FOR THE FIRST POLYNOMIAL---\n");
	for(i=0; i<n1; i++)
	{
		printf("Term %d:\n",i+1);
		printf("Enter the coefficient: ");
		scanf("%d",&poly1[i][1]);
		printf("Enter the degree: ");
		scanf("%d",&poly1[i][0]);          //degrees are stored in poly[i][0]
	}
	
	printf("---ENTER THE TERMS FOR THE SECOND POLYNOMIAL---\n");
	for(i=0; i<n2; i++)
	{
		printf("Term %d:\n",i+1);
		printf("Enter the coefficient: ");
		scanf("%d",&poly2[i][1]);
		printf("Enter the degree: ");
		scanf("%d",&poly2[i][0]);
	}
	
	//initializing result array
	for(i=0; i<n1+n2; i++)
	{
		result[i][0]=0;
		result[i][1]=0;	
	}
	
	i=0; //index for poly1
	j=0; //index for poly2
	k=0; //index for result poly
	
	while(i<n1 && j<n2)
	{
		if (poly1[i][0]==poly2[j][0]) //if degrees of the two polys are same, just add the coeff
		{
			result[k][0]=poly1[i][0]; //the degree of the resultant term will also be the same
			result[k][1]=poly1[i][1] + poly2[j][1]; //adding coeff
			i++;
			j++;
			k++;
		}
		else if(poly1[i][0]>poly2[j][0]) // degree of poly1 > poly2, then the term(degree&coeff) with the higher degree will go to the result as it is.
		{
			result[k][0]=poly1[i][0];
			result[k][1]=poly1[i][1];
			i++;
			k++;
		}
		else  //degree of poly2 > poly1{i.e,(poly2[j][0]>poly1[i][0]);}, then the term(degree&coeff) with the higher degree will go to the result as it is.
		{
			result[k][0]=poly2[j][0];
			result[k][1]=poly2[j][1];
			j++;
			k++;			
		}
	}
	
    // Add remaining terms from poly1 (if any)
    while (i < n1) 
	{
        result[k][0] = poly1[i][0];
        result[k][1] = poly1[i][1];
        i++;
        k++;
    }
    
    // Add remaining terms from poly2 (if any)
    while (j < n2) 
	{
        result[k][0] = poly2[j][0];
        result[k][1] = poly2[j][1];
        j++;
        k++;
    }
	
	//displaying resultant poly
	printf("\nRESULT POLYNOMIAL: ");
	for(i=0; i<k; i++)
	{
		printf("%dx^%d",result[i][1],result[i][0]);

		if(i<k-1)
		{
			printf(" + ");
		}
	}
	printf("\n");
	
	return 0;
}
