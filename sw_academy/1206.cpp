#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];

void input() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int solve() {
	int res = 0;
	for(int i = 2; i < n; i++) {
		int max_height = max(max(arr[i-2], arr[i-1]), max(arr[i+1], arr[i+2]));
		if(max_height < arr[i]) {
			res += arr[i] - max_height;
		}
	}
	return res;
}

int main() {
	for(int tc = 1; tc <= 10; tc++) {
		input();
		int res = solve();
		printf("#%d %d\n", tc, res);
	}
	return 0;
}