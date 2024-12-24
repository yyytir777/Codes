#include <bits/stdc++.h>
#define MAX 100
#define REST 9901
using namespace std;

/*
dp[n][m] = 2*n 배열에 0~m마리의 사자가 배치되는 경우의 수

dp[1][0] + dp[1][1] = 2*1 배열에 0~1마리 배치되는 경우의 수
dp[1][0] = 1
dp[1][1] = 2

dp[2][0] + dp[2][1] + dp[2][2] = 2 * 2 배열에 0~2마리 배치되는 경우의 수
dp[2][0] = 1 = 2C0
dp[2][1] = 4 = 4C1
dp[2][2] = 2 = 

dp[3][0] = 1
dp[3][1] = 6
dp[3][2] = dp[2][2] +dp[2][1]

dp[4][0] = 1
dp[4][1] = 8
dp[4][2] = 
dp[n][m] = dp[n-1][m] + dp[n-1][m-1]

*/

int dp[MAX][MAX];

int main() {
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) dp[i][j] = 1;
            if(j == 1) dp[i][j] = (2 * i) % REST;
            else dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % REST;
        }
    }
    
    int sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += dp[n][i];
    }
    cout << sum;
}