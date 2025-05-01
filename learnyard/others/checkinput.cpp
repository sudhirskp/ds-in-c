#include <iostream>
using namespace std;

int main() {
    char input;
    cout << "Enter single input for check: ";
    cin >> input;
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
        cout << input << " is an alphabet" << endl;
    }
    else if (input >= '0' && input <= '9') {
        cout << input << " is a digit" << endl;
    }
    else {
        cout << input << " is a special character" << endl;
    }

    return 0;
}
