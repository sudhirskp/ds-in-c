#include<iostream>
using namespace std;

class base {
    protected:
        int age;
};

class derived : protected base {
    public:
        void setage(int a) {
            age = a;
        }

        int getage() {
            return age;
        }
};

int main() {
    derived d;
    d.setage(17);
    cout << d.getage() << endl;

    return 0;
}
