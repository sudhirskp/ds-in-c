#include <iostream>
#include <string>

using namespace std;

// Function for bit stuffing
void bitStuffing(const string &input, string &stuffed) {
    int count = 0;

    for (char ch : input) {
        stuffed += ch;

        if (ch == '1') {
            count++;
            if (count == 5) {
                stuffed += '0'; // Add '0' after five consecutive '1's
                count = 0; // Reset the count
            }
        } else {
            count = 0; // Reset count if '0' is encountered
        }
    }
}

// Function for bit destuffing
void bitDestuffing(const string &stuffed, string &destuffed) {
    int count = 0;

    for (size_t i = 0; i < stuffed.length(); i++) {
        destuffed += stuffed[i];

        if (stuffed[i] == '1') {
            count++;
            if (count == 5 && stuffed[i + 1] == '0') {
                i++; // Skip the stuffed '0'
                count = 0; // Reset the count
            }
        } else {
            count = 0; // Reset count if '0' is encountered
        }
    }
}

int main() {
    string input, stuffed, destuffed;

    cout << "Enter binary input data: ";
    cin >> input;

    // Perform bit stuffing
    bitStuffing(input, stuffed);
    cout << "Bit Stuffed Data: " << stuffed << endl;

    // Perform bit destuffing
    bitDestuffing(stuffed, destuffed);
    cout << "Bit Destuffed Data: " << destuffed << endl;

    return 0;
}