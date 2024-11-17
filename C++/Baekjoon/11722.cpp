#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
int arr[MAX];
int dp[MAX];

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for(int i = 0; i < n; i++) dp[i] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    sort(dp, dp+n);
    cout << dp[n-1];
}
int main() {
    input();
    solve();
}