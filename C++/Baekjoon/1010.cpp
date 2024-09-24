#include <bits/stdc++.h>
#define MAX 31
using namespace std;

/*

combination 문제
nCr = n-1Cr-1 + n-1Cr

dp[m][n] => m개 중에서 n개 선택

*/

int dp[MAX][MAX];

int main() {
    int tc;
    cin >> tc;

    dp[1][1] = 1;
    dp[2][1] = 2;
    dp[2][2] = 1;

    int n, m;
    while(tc--) {
        cin >> n >> m;

        for(int i = 3; i <= min(m, i); i++) {
            for(int j = 1; j <= n; j++) {
                if(j == 1) dp[i][j] = dp[i-1][j] + 1;
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }

        cout << dp[m][n] << '\n';
    }
}