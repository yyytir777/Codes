#include <bits/stdc++.h>
#define MAX 101
using namespace std;
/*
dp[i][j] = 남아있는 모든 전깃줄이 서로 교차하지
않게 없애야 하는 전깃줄의 최소 개수

*/

struct Pole {
	int left;
	int right;
};

int cnt;
int dp[MAX];
Pole pole[MAX];

bool compare(Pole a, Pole b) {
	if(a.left < b.left) return true;
	else return false;
}

void input() {
	cin >> cnt;
	
	for(int i=0; i<cnt; i++) {
		cin >> pole[i].left >> pole[i].right;
	}
}

void solve() {
	sort(pole, pole+cnt, compare);

	int max_num = 0;
	for(int i=0; i<cnt; i++) {
		dp[i] = 1;
		for(int j=i-1;j>=0;j--) {
			if(pole[i].right > pole[j].right) dp[i] = max(dp[i], dp[j] + 1);
		}
		max_num = max(max_num, dp[i]);
	}
	cout << cnt - max_num;
}

int main() {
	input();
	solve();
}