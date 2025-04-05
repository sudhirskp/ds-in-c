#include<iostream>
using namespace std;

class outclass{
    public:
    void greet();
};
void outclass::greet(){
    cout<<"Out of the class"<<endl;
}
int main(){
    outclass out;
    out.greet();

}