#include <stdio.h>

struct date{
	int day;
	int month;
	int year;
};

void read(struct date *d){
	
	printf("Enter the day(dd): ");
	scanf("%d",&d->day);
	
	printf("\nEnter the month(mm): ");
	scanf("%d",&d->month);
	
	printf("\nEnter the year(yyyy): ");
	scanf("%d",&d->year);
	
}

void disp(struct date d){
	
	printf("%d/%d/%d", d.day, d.month, d.year);
}

int compare(struct date d1, struct date d2){
	
	if (d1.day==d2.day && d1.month==d2.month && d1.year==d2.year)
	{
		printf("\nTHE TWO DATES ARE EQUAL!");
	}
	else
	{
		printf("\nTHE GIVEN DATES ARE NOT EQUAL!");
	}
	
}

int main(){
	struct date d1,d2;
	
	printf("Enter the first date: \n");
	read(&d1);
	printf("\n");
	
	printf("\nEnter the second date: \n");
	read(&d2);
	printf("\n");
	
	printf("The first date: ");
	disp(d1);
	printf("\n");
	
	printf("The second date: ");
	disp(d2);
	printf("\n");
	
	compare(d1,d2);
	
	return 0;
}
