// 1806 cpp
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, s;
int arr[MAX];

void input() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    int start = 0, end = 0;
    int sum = 0, minLen = INT_MAX;
    while(end < n) {
        sum += arr[end++];
        while(sum >= s) {
            minLen = min(minLen, end - start);
            sum -= arr[start++];
        }
    }

    if(minLen == INT_MAX) cout << "0";
    else cout << minLen;
}

int main() {
    input();
    solve();
    return 0;
}