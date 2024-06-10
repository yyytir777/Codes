#include <bits/stdc++.h>
#define MAX 1025
using namespace std;
int N, M;
int arr[MAX][MAX];
int dp[MAX][MAX] = {0,};

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int answer = dp[x2][y2] + dp[x1 - 1][y1- 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1];
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    for(int i = 2; i <= N; i++) {
        dp[i][1] = dp[i-1][1] + arr[i][1];
    }

    for(int i = 2; i <= N; i++) {
        dp[1][i] = dp[1][i-1] + arr[1][i];
    }

    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    for(int i = 2; i <= N; i++) {
        for(int j = 2; j <= N; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    // dp 완료


    while(M--) {
        solve();
    }
}