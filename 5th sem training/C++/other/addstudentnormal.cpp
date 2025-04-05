#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, course, branch, DOB, gender, address;
    int age;

    getline(cin, name);
    getline(cin, course);
    getline(cin, address);
    getline(cin, branch);
    getline(cin, DOB);
    getline(cin, gender);
    
    cin >> age;

    cout << "Name: " << name << endl;
    cout << "Course: " << course << endl;
    cout << "Branch: " << branch << endl;
    cout << "DOB: " << DOB << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;

    return 0;
}