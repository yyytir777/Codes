// 1253 cpp
#include <bits/stdc++.h>
#define MAX 2002
using namespace std;

int n;
int arr[MAX];

/*
n = 8
binary(0, 9) -> 1 + 10 > 8

*/
bool isGood(int s, int e, int i) {
	int num = arr[i];
	int l = 0, r = n - 1;
	while(l < r) {
		int sum = arr[l] + arr[r];
		if(sum == num) {
			if(l != i && r != i) return true;
			else if(l == i) l++;
			else if(r == i) r--;
		}
		else if(sum < num) l++;
		else r--;
	}
	return false;
}

void input() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
}

void solve() {
	int cnt = 0;

	for(int i = 0; i < n; i++) {
		int num = arr[i];
		if(isGood(0, n-1, i)) cnt++;
	}
	cout << cnt;
}

int main() {
	input();
	solve();
	return 0;
}