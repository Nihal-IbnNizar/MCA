#include <stdio.h>

void array_rev(int arr[], int index, int size)
{
    if (index>=size)
	{
        return;
    }
	else
	{
        array_rev(arr, index + 1, size);
        printf("%d\t", arr[index]);
    }
}

int main()
{
    int i,arr[20],size,index=0;
    
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    
    printf("Enter %d elements:\n", size);
    for (i=0; i<size; i++)
	{
        scanf("%d", &arr[i]);
    }
    printf("Elements in reverse order:\n");
    array_rev(arr, index, size);
    return 0;
}


