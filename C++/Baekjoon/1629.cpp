#include <bits/stdc++.h>
using namespace std;
long long a, b, c;

long long multiply(long long i, long long j, long long k) {
    long long result;
    if (j==1) return i % k;
    
    long long tmp;
    // 짝수일 때
    if(j % 2 == 0) {
        tmp = multiply(i, j / 2, k) % k;
        result = tmp * tmp;
    }
    // 홀수일 때
    else {
        tmp = multiply(i, j / 2, k) % k;
        result = ((tmp * tmp) % k * i) % k;
    }
    
    return result % k;
}

int main() {
    cin >> a >> b >> c;
    cout << multiply(a, b, c);
}