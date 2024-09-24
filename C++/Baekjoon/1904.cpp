#include <bits/stdc++.h>
#define MAX 1000010
#define mod 15746
using namespace std;

long long dp[MAX];

int main() {
    int n;
    cin >> n;

    dp[1] = 1; dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] %= mod;
    }

    cout << dp[n];

    return 0;
}