#include <iostream>
using namespace std;

int main() {
    int n, num, rev = 0;

    /* Input a number from the user */
    cout << "Enter any number to check palindrome: "<<endl;
    cin >> n;

    /* Copy the original value to 'num' */
    num = n;

    /* Find the reverse of n and store it in rev */
    while (n != 0) {
        rev = (rev * 10) + (n % 10);
        n /= 10;
    }

    /* Check if the reverse is equal to 'num' or not */
    if (rev == num) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}
