// 12852 cpp
#include <bits/stdc++.h>
#define MAX 1000001
#define INF 987654321
using namespace std;

int n;
int dp[MAX] = {0,};
int parent[MAX];

void input() {
	cin >> n;
}

void solve() {
	for(int i = 1; i < n; i++) dp[n-i] = INF;
	dp[n] = 0;

	for(int i = n; i > 0; i--) {
		if(i - 1 >= 0 && dp[i - 1] > dp[i] + 1) {
			dp[i - 1] = dp[i] + 1;
			parent[i-1] = i;
		}
		
		if(i % 2 == 0 && dp[i / 2] > dp[i] + 1) {
			dp[i / 2] = dp[i] + 1;
			parent[i/2] = i;
		}

		if(i % 3 == 0 && dp[i / 3] > dp[i] + 1) {
			dp[i / 3] = dp[i] + 1;
			parent[i / 3] = i;
		}
	}

	cout << dp[1] << '\n';

	stack<int> s;
	int index = 1;
	while(true) {
		s.push(index);
		index = parent[index];
		if(index == 0) break;
	}

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	input();
	solve();
	return 0;
}