// 1309 cpp
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

/*
dp[n][0] : [n][0]에 사자를 배치했을 때
dp[n][1] : [n][1]에 사자를 배치했을 때
dp[n][2] : n행에 사자를 배치하지 않았을 때
*/
int n;
int dp[MAX][3] = {0,};

void input() {
	cin >> n;
}

void solve() {
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % 9901;
		dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
		dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
}

int main() {
	input();
	solve();
	return 0;
}