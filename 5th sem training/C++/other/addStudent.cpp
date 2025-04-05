#include<iostream>
using namespace std;

class Student {
    public:
    string name;
    string courese;
    string branch;
    int age;
    string DOB;
    string gender;
    string address;
};
int main(){
    Student data;
    data.name="Sudhir patel";
    data.courese="B.tech";
    data.branch="CSE";
    data.age=20;
    data.DOB="20-09-01";
    data.gender="Male";
    data.address="Ahmedabad";
    for(int i=0;i<6;i++){
        cout<<":"<<data[i]<<endl;
    }

}