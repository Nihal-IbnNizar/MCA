#include <stdio.h>
void Search(int a[], int size, int element)
{
    int positions[size];
    int count=0;

	int i=0;
    for (i=0; i<size; i++)
	{
        if (a[i]==element)
		{
            positions[count] = i;
            count++;
        }
    }
	if (count > 0)
	{
        printf("Element %d found at positions: ", element);
        for (i=0; i<count; i++)
		{
            printf("%d", positions[i]);
            if (i<count-1)
			{
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("Element %d not found in the array.\n", element);
    }
}

int main() {
    int a[] = {10, 20, 30, 20, 40, 20, 50};
    int size = sizeof(a) / sizeof(a[0]);
    int element = 20;

    Search(a, size, element);

    return 0;
}

