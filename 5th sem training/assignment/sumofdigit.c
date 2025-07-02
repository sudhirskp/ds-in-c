#include <stdio.h>

int main() {
    int num, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num != 0) {
        sum += num % 10; // Add the last digit to the sum
        num /= 10;       // Remove the last digit
    }

    printf("The sum of the digits is %d\n", sum);

    return 0;
}
