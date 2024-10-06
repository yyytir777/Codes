#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];

/*
dp[n][k] = dp[n-1][k-1] + dp[n-1][k]
*/

int main() {
    int n, k;
    cin >> n >> k;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= max(i, k); j++) {
            if(j == 0) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }
    cout << dp[n][k];
}