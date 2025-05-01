#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter range to check perfect numbers: ";
    cin >> n;
    cout << "The perfect numbers in the range from 1 to " << n << " are: ";

    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            sum = 0;
            for (int j = 1; j < i; j++) {
                if (i % j == 0) {
                    sum += j;
                }
            }
            if (sum == i) {
                cout << i << " ";
            }
        }
        cout << endl; // For neat output
    }

    return 0;
}
