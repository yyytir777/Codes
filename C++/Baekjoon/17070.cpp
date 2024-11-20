#include <bits/stdc++.h>
#define MAX 17
using namespace std;

int n, cnt = 0;
int arr[MAX][MAX];
int dp[3][MAX][MAX] = {0,};

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
}

// 0 : row // 1 : col // 2 : diagonal //
void solve() {
    dp[0][1][2] = 1;
    for(int i = 3; i <= n; i++) {
        if(arr[1][i] == 0) dp[0][1][i] = dp[0][1][i-1];
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 3; j <= n; j++) {
            if(arr[i][j] == 0) {
                dp[0][i][j] = dp[0][i][j-1] + dp[2][i][j-1];
                dp[1][i][j] = dp[1][i-1][j] + dp[2][i-1][j];

                if(arr[i-1][j] == 0 && arr[i][j-1] == 0) {
                    dp[2][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
                }
            }
        }
    }
    int ans = dp[0][n][n] + dp[1][n][n] + dp[2][n][n];
    cout << ans;
}

int main() {
    input();
    solve();
}