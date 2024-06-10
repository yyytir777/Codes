#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n;
int score[2][MAX];
int dp[2][MAX] = {0,};

void solve() {
    cin >> n;

    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> score[i][j];
        }
    }

    dp[0][1] = score[0][1];
    dp[1][1] = score[1][1];

    for(int i = 2; i <= n; i++) {
        dp[0][i] = score[0][i] + max(dp[1][i-1], dp[1][i-2]);
        dp[1][i] = score[1][i] + max(dp[0][i-1], dp[0][i-2]);
    }

    cout << max(dp[0][n], dp[1][n]) << '\n';
}

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        solve();
    }
}