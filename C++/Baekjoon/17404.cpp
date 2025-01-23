// 17404 cpp
#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321
using namespace std;

int n;
int arr[MAX][3];
int dp[MAX][3];
int ans = INF;

void input() {
    cin >> n;

    int r, g, b;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i][0]>> arr[i][1] >> arr[i][2];
    }
}

void solve() {
    for(int j = 0; j < 3; j++) {
        dp[1][j] = arr[1][j];
        dp[1][(j + 1) % 3] = INF;
        dp[1][(j + 2) % 3] = INF;

        for(int i = 2; i <= n; i++) {
            for(int k = 0; k < 3; k++) {
                dp[i][k] = min(dp[i - 1][(k + 1) % 3], dp[i - 1][(k + 2) % 3]) + arr[i][k];
            }
        }

        ans = min(ans, min(dp[n][(j + 1) % 3], dp[n][(j + 2) % 3]));

        // for(int i = 1; i <= n; i++) {
        //     for(int j = 0; j < 3; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
    }


    cout << ans;
}

int main() {
    input();
    solve();
    return 0;
}