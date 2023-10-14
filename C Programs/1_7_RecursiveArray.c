#include <stdio.h>
void Disp(int a[], int size, int index)
{
    if (index>=size)
	{
        return;
    }
    printf("%d ", a[index]);
    Disp(a, size, index + 1);
}
int main()
{
    int a1[] = {2,3,4,8,5};
    int size = sizeof(a1) / sizeof(a1[0]);
    Disp(a1, size, 0);
    return 0;
}

