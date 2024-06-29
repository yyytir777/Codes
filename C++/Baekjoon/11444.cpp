#include <bits/stdc++.h>
#define REST 1000000007
using namespace std;

long long n;

int main() {
    cin >> n;

    if(n <= 1) {
        cout << n;
        return 0;
    }
    long long a = 0, b = 1, c;
    while(n-- >= 2) {
        c = (a + b) % REST;
        a = b;
        b = c;
    }
    cout << b;
    return 0;
}