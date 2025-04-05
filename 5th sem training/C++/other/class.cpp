#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
        int rollno;
        int contact;
    public:
        //string name;
        int age;

        //constructer - not creat any constructer in Encapsualtion only -> settter/getter create
        // Student(int roll, int con) {
        //     rollno = roll;
        //     contact = con;
        // }

        // int getrollno() {
        //     return rollno;
        // }

        // void setrollno(int roll) {
        //     rollno = roll;
        // }

        // int getcontact() {
        //     return contact;
        // }

        // void setcontact(int con) {
        //     contact = con;
        // }

        Student(int a){
            age = a;
        }
};

int main() {
    //Student s1;
    //Student s1(74, 347823547);
    //s1.name = "Sudhir Patel";
    //s1.age = 20;
    Student s1(23);
    
    
    //cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    //cout << "Roll No: " << s1.getrollno() << endl;
    //cout << "Contact: " << s1.getcontact() << endl;
    //cout << "Age : " << s1.age << endl;

    return 0;
}
