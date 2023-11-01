#include <stdio.h>


void addition(int row,int col, int matrix1[][col], int matrix2[][col], int result[][col])
{
	for(int i=0; i<row; i++){      //since we called it as 'row' instead of 'row1'
		for(int j=0; j<col; j++){
			result[i][j]=matrix1[i][j] + matrix2[i][j];
		}
	}
}

void subtraction(int row,int col, int matrix1[][col], int matrix2[][col], int result[][col])
{
	for(int i=0; i<row; i++){      //since we called it as 'row' instead of 'row1'
		for(int j=0; j<col; j++){
			result[i][j]=matrix1[i][j] - matrix2[i][j];
		}
	}
}


void multiply(int row1,int col1,int matrix1[][col1], int row2,int col2,int matrix2[][col2], int result[][col2])
{
	for(int i=0; i<row1; i++){
		for(int j=0; j<col2; j++){
			result[i][j]=0;           //initializing to zero
			for (int k=0; k<col1; k++){  //iterates thru the col of matrix1 & rows of matrix2
			                             //This loop is used to perform the actual multiplication and summation of products.
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}	
}

int main()
{
	int row1,col1,row2,col2;
	
    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &col1);

    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &col2);
    
    
	int matrix1[row1][col1], matrix2[row2][col2], result[row1][col2]; //for + & -, rows1=row2 & col1=col2
	
	printf("Enter the elements for the first matrix: \n");
	for(int i=0; i<row1; i++)
	{
		for (int j=0; j<col1; j++)
		{
			scanf("%d",&matrix1[i][j]);
		}
	}
	
	printf("Enter the elements for the second matrix: \n");
	for(int i=0; i<row2; i++)
	{
		for (int j=0; j<col2; j++)
		{
			scanf("%d",&matrix2[i][j]);
		}
	}
	
	//MATRIX ADDITION
	if (row1==row2 && col1==col2)
	{
		addition(row1,col1,matrix1,matrix2,result); //pass any one of the row and col since both are same
		printf("THE SUM OF THE MATRICES IS: \n");
		for(int i=0; i<row1; i++){
			for(int j=0; j<col1; j++){
				printf("%d ",result[i][j]);
			}
			printf("\n");
		}	
	}
	else{
		printf("\nMATRIX ADDITION IS NOT POSSIBLE!"); //since it has different dimensions
	}
	
	//MATRIX SUBTRACTION
	if (row1==row2 && col1==col2)
	{
		subtraction(row1,col1,matrix1,matrix2,result); //pass any one of the row and col since both are same
		printf("THE DIFFERENCE OF THE MATRICES IS: \n");
		for(int i=0; i<row1; i++){
			for(int j=0; j<col1; j++){
				printf("%d ",result[i][j]);
			}
			printf("\n");
		}	
	}
	else{
		printf("\nMATRIX SUBTRACTION IS NOT POSSIBLE!"); //since it has different dimensions
	}
	
	//MATRIX MULTIPLICATION
	if (col1!=row2){
    	printf("MATRIX MULTIPLICATION IS NOT POSSIBLE!\n"); //The no of columns of matrix 1 must be = no of rows of matrix 2
	}
	else if (col1==row2)
	{
		multiply(row1,col1,matrix1,row2,col2,matrix2,result);
		printf("\nTHE PRODUCT OF THE MATRICES IS: \n");
		for(int i=0; i<row1; i++){
			for(int j=0; j<col2; j++){
				printf("%d ",result[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
