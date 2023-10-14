#include <stdio.h>
void read(int a[], int size)
{
    printf("Enter %d elements:\n", size);
    int i;
    for (i = 0; i<size; i++)
	{
        scanf("%d", &a[i]);
    }
}
void disp(int a[], int size)
{
    printf("Array elements: ");
    int i;
    for (i=0; i<size; i++)
	{
        printf("%d ", a[i]);
    }
    printf("\n");
}
void sort(int a[], int size)
{
	int i,j;
    for (i = 0; i<size-1; i++)
	{
        for (j = 0; j<size-i-1; j++)
		{
            if (a[j]>a[j+1])
			{
			    int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int a[size];

    read(a,size);
    printf("\n");

    printf("Before sorting:\n");
    disp(a, size);

    sort(a, size);

    printf("\nAfter sorting in ascending order:\n");
    disp(a, size);

    return 0;
}

