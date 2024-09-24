#include <bits/stdc++.h>
#define MAX 30
using namespace std;

int dp[MAX] = {0,};
int weight[MAX];
int profit[MAX];

int main() {
    int n;
    cin >> n;

    int t, p;
    for(int i = 1; i <= n; i++) {
        cin >> t >> p;
        weight[i] = t;
        profit[i] = p;
    }

    for(int i = n; i > 0; i--) {
        if (i + weight[i] - 1 <= n) {
            dp[i] = max(dp[i+1], dp[i + weight[i]] + profit[i]);
        }
        else {
            dp[i] = dp[i+1];
        }
    }

    cout << dp[1];

    return 0;
}