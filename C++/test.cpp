#include <iostream>
using namespace std;

int main(){
    int a = 5, b = 3, c = 12;
    int t1, t2, t3;
    t1 = a && b;
    t2 = a || b;
    t3 = !c;
    printf("%d", t2);
    return 0;
}