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
        p[i].degree = z;
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
            if (p[i].coefficient>0 && i<d) {
                printf("%dx^%d + ", p[i].coefficient, p[i].degree);
            }
			else if (p[i].coefficient<0) {
                printf("%dx^%d - ", -p[i].coefficient, p[i].degree);
            }
        }
    }
}

void subtract(struct polynomial p1[], int d1, struct polynomial p2[], int d2, struct polynomial result[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i <= d1 && j <= d2) {
        if (p1[i].degree > p2[j].degree) {
            result[k].degree = p1[i].degree;
            result[k].coefficient = p1[i].coefficient;
            i++;
        }
		else if (p1[i].degree < p2[j].degree) {
            result[k].degree = p2[j].degree;
            result[k].coefficient = -p2[j].coefficient; 
            j++;
        }
		else { //(p1[i].degree == p2[j].degree)
            result[k].degree = p1[i].degree;
            result[k].coefficient = p1[i].coefficient - p2[j].coefficient;
            i++;
            j++;
        }
        k++;
    }

    while (i <= d1) {
        result[k].degree = p1[i].degree;
        result[k].coefficient = p1[i].coefficient;
        i++;
        k++;
    }
    while (j <= d2) {
        result[k].degree = p2[j].degree;
        result[k].coefficient = -p2[j].coefficient;
        j++;
        k++;
    }
}

int main() {
    int d1, d2;

    printf("Enter the highest degree of polynomial 1: ");
    scanf("%d", &d1);
    printf("Enter the highest degree of polynomial 2: ");
    scanf("%d", &d2);

    struct polynomial p1[d1];
    struct polynomial p2[d2];
    struct polynomial result[d1 > d2 ? d1 : d2];

    printf("-----ENTER THE TERMS OF FIRST POLYNOMIAL-----\n");
    read(p1, d1);
    printf("-----ENTER THE TERMS OF SECOND POLYNOMIAL-----\n");
    read(p2, d2);

    printf("THE FIRST POLYNOMIAL IS: ");
    disp(p1, d1);
    printf("\nTHE SECOND POLYNOMIAL IS: ");
    disp(p2, d2);

    subtract(p1, d1, p2, d2, result);
    printf("\nTHE RESULTANT POLYNOMIAL IS: ");
    disp(result, d1 > d2 ? d1 : d2);

    return 0;
}

