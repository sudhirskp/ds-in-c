#include <iostream>
#include <string>

using namespace std;
string data, divisor, temp, total;
int datalen, divlen, len;
bool flag = true;

void check();

int main() {
    cout << "Enter the total bits of data: ";
    cin >> datalen;

    cout << "Enter the total bits of divisor: ";
    cin >> divlen;

    len = datalen + divlen - 1;

    cout << "Enter the data: ";
    cin >> data;

    cout << "Enter the divisor: ";
    cin >> divisor;

    // Append zeros to data to match total length
    total = data;
    temp = data;
    total.append(divlen - 1, '0');

    check();

    // Append CRC (remainder) to the original data
    for (int i = 0; i < divlen - 1; i++) {
        temp += data[i];
    }

    cout << "\nTransmitted Code Word: " << temp << endl;

    cout << "\nEnter the received code word: ";
    cin >> total;

    check();

    // Check for errors
    for (int i = 0; i < divlen - 1; i++) {
        if (data[i] == '1') {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Successful!! No error detected." << endl;
    else
        cout << "Received code word contains errors..." << endl;

    return 0;
}

void check() {
    string remainder = total.substr(0, divlen);
    int j = divlen;

    while (j <= len) {
        if (remainder[0] == '1') {
            for (int i = 1; i < divlen; i++) {
                remainder[i - 1] = (remainder[i] == divisor[i]) ? '0' : '1';
            }
        } else {
            for (int i = 1; i < divlen; i++) {
                remainder[i - 1] = remainder[i];
            }
        }
        remainder[divlen - 1] = (j < total.length()) ? total[j++] : '0';
    }

    data = remainder.substr(0, divlen - 1);
}
