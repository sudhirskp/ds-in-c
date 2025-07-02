#include <stdio.h>
#include<conio.h>
#include <ctype.h> // For tolower() function

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Convert the character to lowercase for easier comparison
    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        printf("%c is a vowel.\n", ch);
    } else if ((ch >= 'a' && ch <= 'z')) {
        printf("%c is a consonant.\n", ch);
    } else {
        printf("%c is not an alphabetic character.\n", ch);
    }

    return 0;
}
