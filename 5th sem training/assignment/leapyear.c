#include <stdio.h>

int main() {
    int n;
    printf("Enter Year for check ,leap year : ");
    scanf("%d", &n);
    if ((n % 4 == 0 && n%100!=0) || (n%400==0)){
        printf("%d is a leap year", n);
    }
    else{
        printf("%d is not a leap year", n);
    }
    return 0;
}
