#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    int binaryArray[32];
    int i = 0;

    while (decimal > 0) {
        binaryArray[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryArray[j]);
    }
}

// // Function to convert binary to decimal
// int binaryToDecimal(char binary[]) {
//     int decimal = 0, i = 0;
//     int length = strlen(binary);

//     for (int j = length - 1; j >= 0; j--) {
//         decimal += (binary[j] - '0') * pow(2, i);
//         i++;
//     }

//     return decimal;
// }

// Function to perform unary operations
int unaryOperation(char operator, int operand) {
    switch (operator) {
        case '+':
            return operand;
        case '-':
            return -operand;
        case '~':
            return ~operand;
        default:
            printf("Invalid unary operator: %c\n", operator);
            return 0;
    }
}

// Function to perform binary operations
int binaryOperation(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '%':
            return operand1 % operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            printf("Invalid binary operator: %c\n", operator);
            return 0;
    }
}

int main() {
    char operator;
    int operand1, operand2, result;

    printf("Enter the operation (+, -, *, /, %, ^, ~): ");
    scanf(" %c", &operator);

    if (operator == '~') {
        printf("Enter the operand: ");
        scanf("%d", &operand1);
        result = unaryOperation(operator, operand1);
    } else {
        printf("Enter the operands: ");
        scanf("%d %d", &operand1, &operand2);
        result = binaryOperation(operator, operand1, operand2);
    }

    printf("Result: %d\n", result);

    if (operator != '~') {
        printf("Binary equivalent: ");
        decimalToBinary(result);
        printf("\n");
    }

    return 0;
}