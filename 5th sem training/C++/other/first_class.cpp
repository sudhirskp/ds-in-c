#include <iostream>
using namespace std;

int main() {
    class first_class {
        public:
        string name;
        int age;
    };
    
    first_class access;
    access.name = "Sudhir Patel";
    access.age = 18;

    cout << "Name: " << access.name << endl;
    cout << "Age: " << access.age << endl;

    return 0;
}
