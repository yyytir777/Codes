#include <iostream>
using namespace std;

int cnt = 0;

int bin(int n, int k){
    cnt += 1;
    if(k == 0 || n == k)
        return 1;
    else
        return bin(n-1, k-1) + bin(n-1, k);
}

int main(){
    bin(100, 3);
    cout << cnt;
    return 0;
}