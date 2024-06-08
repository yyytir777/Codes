#include <bits/stdc++.h>
using namespace std;
int a, b, c;

long long multiply(int a, int b, int c) {
    if (b==1) return a % c;
    return (a * multiply(a, b-1, c)) % c;
}

int main() {
    cin >> a >> b >> c;

    for(int i = 1; i <= b; i++) {
        a *= a;
        a %= c;
    }
    cout << a;
    // cout << multiply(a, b, c);
    return 0;
}