#include <stdio.h>

// Define a structure to represent a polynomial term
struct Term {
    int coefficient;
    int exponent;
};

// Function to read a polynomial
void readPolynomial(struct Term poly[], int n) {
    printf("Enter the polynomial terms (in descending order of exponents):\n");

    for (int i = 0; i < n; i++) {
        printf("Term %d:\n", i + 1);
        printf("Enter coefficient: ");
        scanf("%d", &poly[i].coefficient);
        printf("Enter exponent: ");
        scanf("%d", &poly[i].exponent);
    }
}

// Function to add two polynomials
void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int *nResult) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].exponent > poly2[j].exponent) {
            result[k].coefficient = poly1[i].coefficient;
            result[k].exponent = poly1[i].exponent;
            i++;
        } else if (poly1[i].exponent < poly2[j].exponent) {
            result[k].coefficient = poly2[j].coefficient;
            result[k].exponent = poly2[j].exponent;
            j++;
        } else {
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            result[k].exponent = poly1[i].exponent;
            i++;
            j++;
        }
        k++;
    }

    while (i < n1) {
        result[k].coefficient = poly1[i].coefficient;
        result[k].exponent = poly1[i].exponent;
        i++;
        k++;
    }

    while (j < n2) {
        result[k].coefficient = poly2[j].coefficient;
        result[k].exponent = poly2[j].exponent;
        j++;
        k++;
    }

    *nResult = k; // Store the number of terms in the result polynomial
}

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int n) {
    printf("Polynomial: ");
    for (int i = 0; i < n; i++) {
        printf("%d", poly[i].coefficient);
        if (poly[i].exponent != 0) {
            printf("x^%d", poly[i].exponent);
        }
        if (i < n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);

    struct Term polynomial1[n1];
    readPolynomial(polynomial1, n1);

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    struct Term polynomial2[n2];
    readPolynomial(polynomial2, n2);

    struct Term result[n1 + n2];
    int nResult;

    addPolynomials(polynomial1, n1, polynomial2, n2, result, &nResult);

    printf("Resultant Polynomial after addition:\n");
    displayPolynomial(result, nResult);

    return 0;
}

