#include <bits/stdc++.h>
#define MAX 101
#define mod 1000000000
using namespace std;

int n;
int dp[MAX][10] = {0,};

/*
dp[i][j] = i자리수이고 j로 끝나는 계단수의 개수

dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

j = 0일 때 -> dp[i][j] = dp[i-1][j+1]
j = 0일 때 -> dp[i][j] = dp[i-1][j-1]

*/

int main() {
    cin >> n;

    for(int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) dp[i][j] = dp[i-1][j+1];
            else if(j == 9) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= mod;
        }
    }

    long long sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += dp[n][i];
        sum %= mod;
    }
    cout << sum;
    
    return 0;
}