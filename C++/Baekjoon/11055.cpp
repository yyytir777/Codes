#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
int dp[MAX];
int arr[MAX];

void input() {
	int i = 0; cin >> n;
	while(n--) cin >> arr[i++];
}

void solve() {
	int sum=0, max_dp=0, max_sum;
	for(int i=0; i<n; i++) {
		dp[i]=1;
		sum += arr[i];
		for(int j = i-1; j>=0; j--) {
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				sum += arr[j];
			}
		}
		if(max_dp < dp[i]) {
			max_dp = dp[i];
			max_sum = sum;
		}
	}
	cout << max_sum;
}

int main() {
	input();
	solve();
}