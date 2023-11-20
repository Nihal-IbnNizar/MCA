#include<stdio.h>
int main()
{
	int sp[10][3],t,k=0,i,j,n;
	
	printf("Enter the size of array: "); //if its a 3x3 matrix, enter 3
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&t);
			if(t!=0){
				sp[k][0]=i;
				sp[k][1]=j;
				sp[k][2]=t;
				k++;
			}
		}
    }    
	k--;
			
	printf("\nRow\tColoumn\tValue\n");

	for(i=0;i<=k;i++){
		printf("%d\t%d\t%d\n",sp[i][0],sp[i][1],sp[i][2]);
	}

    return 0;
}