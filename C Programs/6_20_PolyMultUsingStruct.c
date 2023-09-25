#include <stdio.h>
#include <stdlib.h>

struct polynomial {
    int coefficient;
    int degree;
};

void read(struct polynomial p[], int d) {
    int i,z;
    z=d;
    for (i=0; i<=d; i++, z--) {
        p[i].degree=z;
        printf("Coefficient of x^%d = ", z);
        scanf("%d", &p[i].coefficient);
    }
    printf("\n");
}

void disp(struct polynomial p[], int d) {
    int i;
    for (i=0; i<=d; i++) {
        if (p[i].degree == 0) {
            printf("%d", p[i].coefficient);
        }
		else {
            if (p[i].coefficient>0 && i < d) {
                printf("%dx^%d + ", p[i].coefficient, p[i].degree);
            }
			else if (p[i].coefficient<0) {
                printf("%dx^%d -", -p[i].coefficient, p[i].degree);
            }
        }
    }
}

void multiply(struct polynomial p1[], int d1, struct polynomial p2[], int d2, struct polynomial result[]) {
    int i, j, k;

    for (i = 0; i <= d1 + d2; i++) {
        result[i].degree = i;
        result[i].coefficient = 0;
    }

    for (i = 0; i <= d1; i++) {
        for (j = 0; j <= d2; j++) {
            k = i + j;
            result[k].coefficient += p1[i].coefficient * p2[j].coefficient;
        }
    }
}

int main() {
    int d1, d2;

    printf("Enter the highest degree of polynomial 1: ");
    scanf("%d", &d1);
    printf("Enter the highest degree of polynomial 2: ");
    scanf("%d", &d2);

    struct polynomial p1[d1 + 1];
    struct polynomial p2[d2 + 1];
    struct polynomial result[d1 + d2 + 1];

    printf("-----ENTER THE TERMS OF FIRST POLYNOMIAL-----\n");
    read(p1, d1);
    printf("-----ENTER THE TERMS OF SECOND POLYNOMIAL-----\n");
    read(p2, d2);

    printf("THE FIRST POLYNOMIAL IS: ");
    disp(p1, d1);
    printf("\nTHE SECOND POLYNOMIAL IS: ");
    disp(p2, d2);

    multiply(p1, d1, p2, d2, result);
    printf("\nTHE RESULTANT POLYNOMIAL IS: ");
    disp(result, d1 + d2);

    return 0;
}

