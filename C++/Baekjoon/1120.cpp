#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

string a, b;
int min_diff = INF;

void input() {
	cin >> a >> b;
}

int calc(int idx) {
	int cnt = 0;
	for(int i = idx; i < a.length() + idx; i++) {
		if(a[i - idx] != b[i]) cnt++;
	}
	return cnt;
}

void solve() {
	for(int i = 0; i <= b.length() - a.length(); i++) {
		int candidate_min = calc(i);
		if(min_diff > candidate_min) min_diff = candidate_min;
	}
	cout << min_diff;
}

int main() {
	input();
	solve();
	return 0;
}