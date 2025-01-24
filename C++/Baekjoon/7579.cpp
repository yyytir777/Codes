// 7579 cpp
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, m, sum = 0;
int app[MAX];
int cost[MAX];
int dp[MAX][MAX * MAX];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> app[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
        sum += cost[i];
    }
}

void solve() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(cost[i] == 0) ans += app[i];
    }
    if(ans >= m) {
        cout <<"0";
        return;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            // cost의 비용을 사용할 수 있을 때
            if(j - cost[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]] + app[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    for(int i = 1; i <= sum; i++) {
        if(dp[n][i] >= m) {
            cout << i << '\n';
            break;
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}