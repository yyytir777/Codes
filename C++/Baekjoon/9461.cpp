#include <bits/stdc++.h>
#define MAX 101
using namespace std;

long long p[MAX] = {0,};

long long solve() {
    int n;
    cin >> n;

    if(p[n] == 0) {
        for(int i = 6; i <= n; i++) {
            p[i] = p[i-1] + p[i-5];
        }
    }

    return p[n];
}

int main() {
    int tc;
    cin >> tc;

    p[1] = 1, p[2] = 1, p[3] = 1;
    p[4] = 2, p[5] = 2;

    while(tc--) {
        cout << solve() << '\n';
    }
}