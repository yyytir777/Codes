#include <iostream>
using namespace std;

class A{
private:
    int floor;
    
public:
    A();

    A(int s){
        floor = s;
    }

    int getfloor(){
        return floor;
    }
};

int main(){
    A a(3);
    A b();
}