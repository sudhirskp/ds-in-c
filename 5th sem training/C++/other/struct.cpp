#include <iostream>
using namespace std;

int main() {
    struct first_class {
        string name;
        first_class *next;
    }*x;
    x = new first_class;
    x->name = "Sudhir Patel";
    x->next = NULL;

    cout << "Name : " << x->name << endl;
    cout << "next : " << x->next << endl;

    return 0;
}
