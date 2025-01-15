// 2096 cpp
#include <bits/stdc++.h>
using namespace std;

int n;
int max_dp[3] = {0,}, min_dp[3] = {0,}, value[3];

void input() {
    cin >> n;
    int a, b, c;
    for(int i = 0; i < n; i++) {
        cin >> value[0] >> value[1] >> value[2];

        if(i == 0) {
            max_dp[0] = value[0];
            max_dp[1] = value[1];
            max_dp[2] = value[2];

            min_dp[0] = value[0];
            min_dp[1] = value[1];
            min_dp[2] = value[2];
        }
        else {
            a = max(max_dp[0], max_dp[1]) + value[0];
            b = max(max_dp[0], max(max_dp[1], max_dp[2])) + value[1];
            c = max(max_dp[1], max_dp[2]) + value[2];
            max_dp[0] = a, max_dp[1] = b, max_dp[2] = c;

            a = min(min_dp[0], min_dp[1]) + value[0];
            b = min(min_dp[0], min(min_dp[1], min_dp[2])) + value[1];
            c = min(min_dp[1], min_dp[2]) + value[2];
            min_dp[0] = a, min_dp[1] = b, min_dp[2] = c;
        }
    }
}

void solve() {
    cout << max(max_dp[0], max(max_dp[1], max_dp[2])) << " ";
    cout << min(min_dp[0], min(min_dp[1], min_dp[2]));
}

int main() {
    input();
    solve();
    return 0;
}