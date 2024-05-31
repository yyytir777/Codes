#include <bits/stdc++.h>
#define MAX 1010
using namespace std;
long long dp[MAX] = {0,};

int main() {
    int n;
    cin >> n;

    dp[1] = 1, dp[2] = 3;
    if(dp[n] == 0) {
        for(int i = 3; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
        }
    }

    cout << dp[n];
}