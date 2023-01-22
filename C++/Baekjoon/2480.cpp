#include <iostream>
using namespace std;



int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int m = max(max(a, b), c);
    int price;

    if(a == b && b == c){ //세개 모두 다른경우
        price = a * 1000 + 10000;
    }
    else if(a == b || a == c){
        price = a * 100 + 1000;
    }
    else if(b == c){
        price = c * 100 + 1000;
    }
    else{
        price = m * 100;
    }
    cout << price;
    
    return 0;
}