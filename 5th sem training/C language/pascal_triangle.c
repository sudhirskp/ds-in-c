#include <stdio.h>

// Function to calculate binomial coefficient
int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to print Pascal's Triangle
void printPascal(int n) {
    for (int line = 0; line < n; line++) {
        for (int i = 0; i <= line; i++)
            printf("%d ", binomialCoeff(line, i));
        printf("\n");
    }
}

int main() {
    int n = 5; // Number of rows
    printPascal(n);
    return 0;
}
