#include <iostream>
using namespace std;

bool isPerfectNum(int num) {
    int sum = 0;
    for(int i = 1; i < num; i++) {
        if(num % i == 0) sum += i;
    }
    if(num == sum) return true;
    else return false;
}


int main() {
    int r = 0;
    for(int i = 1; i <= 100; i++) {
        if(isPerfectNum(i)) r += i;
    }

    cout << r;
}