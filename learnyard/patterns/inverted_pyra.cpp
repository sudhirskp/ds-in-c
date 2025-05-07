// *********
//  *******
//   *****
//    ***
//     *  

#include<iostream>
using namespace std;

int main() {
    int n = 5; // number of levels
    for (int i = 1; i <= n; i++) {
        // Printing spaces
        for (int j = 1; j < i; j++) {
            cout << " ";
        }
        // Printing stars
        for (int j = 1; j <= (2*n-(2 * i - 1)); j++) {
           cout<<"*";
        }
        cout << endl;
    }
    return 0;
}
