#include <stdio.h>
#include <stdlib.h>
void inputPolynomial(int *coefficients, int degree) {
printf("Enter the coefficients for the polynomial from lowest degree to highest degree:\n");
for (int i = 0; i <= degree; i++) {
printf("Coefficient for x^%d: ", i);
        scanf("%d", &coefficients[i]);
    }
}

// Function to display a polynomial
void displayPolynomial(int *coefficients, int degree) {
    printf("Resultant Polynomial: ");
    for (int i = degree; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (i == degree) {
printf("%dx^%d", coefficients[i], i);
} else {
printf("%+dx^%d", coefficients[i], i);
}
}
}
printf("\n");
}
void addPolynomials(int *poly1, int *poly2, int *result, int degree) {
for (int i = 0; i <= degree; i++) {
result[i] = poly1[i] + poly2[i];
}
}
int main() {
int degree;
printf("Enter the maximum degree of x: ");
scanf("%d", &degree);
int *coefficients1 = (int *)malloc((degree + 1) * sizeof(int));
int *coefficients2 = (int *)malloc((degree + 1) * sizeof(int));
int *result = (int *)malloc((degree + 1) * sizeof(int));
printf("Enter Polynomial-1:\n");
inputPolynomial(coefficients1, degree);
printf("Enter Polynomial-2:\n");
inputPolynomial(coefficients2, degree);
addPolynomials(coefficients1, coefficients2, result, degree);
displayPolynomial(result, degree);
free(coefficients1);
free(coefficients2);
free(result);
return 0;
}