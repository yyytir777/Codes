// 2212 cpp
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int n, k;
int sensor[MAX];

void input() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> sensor[i];
    }
}

void solve() {
    sort(sensor, sensor+n);

    
}

void print() {
    for(int i = 0; i < n; i++) {
        printf("%d ", sensor[i]);
    }
}

int main() {
    input();
    solve();
    print();
    return 0;
}