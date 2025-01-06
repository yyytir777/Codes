// 14916 cpp
#include <bits/stdc++.h>
#define MAX 100001
#define INF 987654321
using namespace std;

int n;
int dp[MAX];

void input() {
    cin >> n;
}

void solve() {
    dp[1] = INF;
    dp[2] = 1;
    dp[3] = INF;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 3;

    for(int i = 7; i <= n; i++) {
        dp[i] = min(dp[i-5] + 1, dp[i-2] + 1);
    }

    int result = dp[n] == INF ? -1 : dp[n];
    cout << result << '\n';
}

void print_dp() {
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
}
int main() {
    input();
    solve();
    // print_dp();
    return 0;
}