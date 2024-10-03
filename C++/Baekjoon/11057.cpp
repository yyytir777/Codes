#include <bits/stdc++.h>
#define REST 10007
using namespace std;

/*

dp[n][m] : m으로 끝나는 n자리 오르막 수의 개수

dp[1][1] = 1

n자리 오르막 수의 개수 => 9로 끝나는 n + 1자리 오르막 수의 개수 => dp[n+1][9]
*/

int dp[1001][10] = {0,};

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < 10; i++) dp[1][i] = 1;

    for(int i = 2; i <= n + 1; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % REST;
        }
    }

    cout << dp[n+1][9];
    return 0;
}