#include <bits/stdc++.h>
#define REST 1000000000
#define MAX 201
using namespace std;

/*
dp[n][k] = k개를 더해서 n이 되는 경우의 수
dp[1][1] = 1
dp[2][1] = 1
dp[3][1] = 1
...

dp[1][2] = 2 / (1, 0) (0, 1)
dp[2][2] = 3 / (2, 0) (1, 1) (0, 2)
dp[3][2] = 
dp[4][2] = 3
dp[5][2] = 4

dp[1][3] = 3 / (0, 0, 1) (0, 1, 0) (1, 0, 0)
dp[2][3] = 0
dp[3][3] = dp[2][3] = 1
dp[4][3] = dp[2][2] + dp[3][2] = 3
dp[5][3] = dp[2][2] + dp[3][2] + dp[4][2] 
=>  (1, 2, 2) (2, 2, 1) (2, 1, 1) (1, 1, 3) (1, 3, 1) (3, 1, 1)
*/

int main() {
    int n, k;
    cin >> n >> k;

    int dp[MAX][MAX];

    for(int i = 1; i <= n; i++) dp[i][1] = 1;
    for(int i = 1; i <= k; i++) dp[1][i] = i;

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % REST;
        }
    }

    cout << dp[n][k];
    return 0;
}