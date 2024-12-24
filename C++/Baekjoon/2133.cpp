#include <bits/stdc++.h>
#define MAX 31
using namespace std;

int n;
int dp[MAX];

/*

dp[4] = dp[2] * dp[2] + 2
dp[6] = dp[2]dp[4] + dp[4]dp[2] = dp[2] * 2 + dp[4] * 3
dp[8] = dp[6]dp[2] + dp[4]dp[4] = dp[6] * dp[2] + dp

*/
int main() {
    cin >> n;

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 3;

    if(n % 2 != 0) {
        cout << "0";
        return;
    }

    for(int i = 4; i <= n; i++) {
        
    }

    cout << dp[n];
    return;
}