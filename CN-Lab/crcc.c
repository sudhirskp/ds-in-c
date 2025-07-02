#include <stdio.h>
#include <string.h>

char data[100], div[20], temp[100], total[100];
int datalen, divlen, len, flag = 1;

void check();

int main() {
    int i;

    printf("Enter the total bits of data: ");
    scanf("%d", &datalen);

    printf("Enter the total bits of divisor: ");
    scanf("%d", &divlen);

    len = datalen + divlen - 1;

    printf("Enter the data: ");
    scanf("%s", data);

    printf("Enter the divisor: ");
    scanf("%s", div);

    // Prepare total by appending zeros
    for (i = 0; i < datalen; i++) {
        total[i] = data[i];
        temp[i] = data[i];
    }
    for (i = datalen; i < len; i++) {
        total[i] = '0';
    }
    total[len] = '\0';

    check();

    // Append CRC (remainder) to the original data
    for (i = 0; i < divlen - 1; i++) {
        temp[datalen + i] = data[i];
    }
    temp[datalen + divlen - 1] = '\0';

    printf("\nTransmitted Code Word: %s\n", temp);

    printf("Enter the received code word: ");
    scanf("%s", total);

    check();

    // Check for errors
    for (i = 0; i < divlen - 1; i++) {
        if (data[i] == '1') {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("Successful!! No error detected.\n");
    else
        printf("Received code word contains errors...\n");

    return 0;
}

void check() {
    int i, j;
    for (j = 0; j < divlen; j++) {
        data[j] = total[j];
    }

    int k = j;
    while (k <= len) {
        if (data[0] == '1') {
            for (i = 1; i < divlen; i++) {
                data[i] = (data[i] == div[i]) ? '0' : '1';
            }
        }

        // Shift data
        for (i = 0; i < divlen - 1; i++) {
            data[i] = data[i + 1];
        }

        data[divlen - 1] = total[k++];
    }
}
