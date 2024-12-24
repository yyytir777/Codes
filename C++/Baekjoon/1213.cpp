#include <bits/stdc++.h>
using namespace std;

string str;
int odd_cnt = 0;
int cnt[26] = {0,};

void input() {
	cin >> str;
}

void solve() {
	// 각 알파벳 횟수 계산
	for(int letter : str) {
		cnt[letter - 65]++;
	}

	// 홀수인 횟수 계산
	for(int letter_cnt : cnt) {
		if(letter_cnt % 2 != 0) odd_cnt++;
	}

	//홀수 횟수가 2개 이상이면 불가능
	if(odd_cnt >= 2) {
		cout << "I'm Sorry Hansoo";
		return;
	}

	//팰린드롬이 가능한 경우 해당 정답 계산 및 출력 (홀수 횟수는 단 한 개)
	string res = "";
	int odd_idx = -1;
	for(int i = 0; i < 26; i++) {
		if(cnt[i] % 2 != 0) odd_idx = i;
		for(int j = 0; j < cnt[i] / 2; j++) {
			res += char(i + 65);
		}
	}

	if(odd_idx != -1) res += char(odd_idx + 65);

	string rest = "";
	if(odd_idx == -1) {
		for(int i = res.length() - 1; i >= 0 ; i--) {
			rest += res[i];
		}
	}
	else {
		for(int i = res.length() - 2; i >= 0 ; i--) {
			rest += res[i];
		}	
	}
	
	res += rest;
	cout << res;
}

int main() {
	input();
	solve();
	return 0;
}