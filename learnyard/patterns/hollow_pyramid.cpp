//     *
//    * *
//   *   *
//  *     *
// *********

#include<iostream>
using namespace std;

int main() {
    int n = 5; // number of levels
    for (int i = 1; i <= n; i++) {
        // Printing spaces
        for (int j = i; j < n; j++) {
            cout << " ";
        }
        // Printing stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            if(i==1 || j==1 || i==n || j==2*i-1){
            cout << "*";
            }
            else{
                cout<<" ";
            }
        }
        cout << endl;
    }
    return 0;
}
