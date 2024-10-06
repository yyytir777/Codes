#include <bits/stdc++.h>
#define INF 987654321
#define MAX 100001
using namespace std;

int dp[MAX];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;

    // 1로만 이루어졌다고 가정 (max값)
    for(int i = 0; i <= n; i++) dp[i] = i;

    for(int i = 0; i <= n; i++) {        
        for(int j = 1; j*j <= i; j++) dp[i] = min(dp[i], dp[i-j*j] + 1);
    }

    cout << dp[n];
    return 0;
}