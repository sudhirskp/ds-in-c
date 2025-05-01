#include <iostream>
#include<cmath>
using namespace std;

int main() {
    // int n, t, sum = 0;
    // cout << "Enter range to find Armstrong number: ";
    // cin>>n;
    // cout << "Armstrong number from  "<<1<< " to "<<n<< " is/are: ";
    
    // for(int i=1;i<=n;i++) {
    //     sum=0;
    //     t=i;
    //     int r = t % 10;
    //     sum += r * r * r;
    //     t /= 10;
    
    //    if (i == sum) {
    //     cout<<i<<" ";
    //    }
    // }

/*-----------------------------------------------------------------------------------------------*/

     int num, lastDigit, digits, sum, i, end;

    /* Input upper limit from user */
    /* Input number from user */
    cout << "Enter the number : ";
    cin >> end;

    cout << "Armstrong number between 1 to entered number are: \n";

    for( i = 1; i <= end; i++)
    {
        sum = 0;

        /* Copy the value of num for processing */
        num = i;

        /* Find total digits in num */
        digits = (int) log10(num) + 1;

        /* Calculate sum of power of digits */
        while(num > 0)
        {
            /* Extract last digit */
            lastDigit = num % 10;

            // Find sum of power of digits

            sum = sum + pow(lastDigit, digits);

            /* Remove the last digit */
            num = num / 10;
        }

        /* Check for Armstrong number */
        if(i == sum)
        {
            cout << i <<" ";
        }

    }
    return 0;
}
