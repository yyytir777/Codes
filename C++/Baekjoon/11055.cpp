#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
int dp[MAX];
int arr[MAX];
vector<int> sum_vector;

void input() {
	int i = 0; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	for(int i=0; i<n; i++) {
		dp[i] = arr[i];
		for(int j = n-1; j >= 0; j--) { 
			if(arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}
	sort(dp, dp+n);
	cout << dp[n-1];
}

int main() {
	input();
	solve();
}