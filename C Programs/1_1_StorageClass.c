#include <stdio.h>
int a,b=5;  //Global variable
void disp()
{
	static int d,e=3;
	printf("%d%d\n",d++,e++); //Static variable
}
void disp1()
{
	register int c=2;
	a=b+c;
	a=a+20; 
	printf("%d",a);
}
int main()
{
	int c=2; //Local variable
	disp();
	disp1();
	printf("\n%d\n%d\n%d",a,b,c);
	return 0;
}

