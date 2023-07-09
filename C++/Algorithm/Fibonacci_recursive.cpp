#include <iostream>
using namespace std;

int cnt = 0;

long long fib(long long n){
    if(n <= 1){
        cnt++;
        return n;
    }
    else{
        cnt++;
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    cout << fib(4) << '\n';
    cout << cnt << '\n';


}