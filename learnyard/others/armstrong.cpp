#include <iostream>
using namespace std;

int main() {
    int n, t, sum = 0;
    cout << "Enter number to check if it's an Armstrong number: ";
    cin >> n;
    t = n;
    while (t > 0) {
        int r = t % 10;
        sum += r * r * r;
        t /= 10;
    }
    if (n == sum) {
        cout << n << " is an Armstrong number." << endl;
    } else {
        cout << n << " is not an Armstrong number." << endl;
    }
    return 0;
}
