#include <bits/stdc++.h>
using namespace std;

string s, t;
bool isPossible = false;
queue<string> q;

void input() {
	cin >> s >> t;
}

string reverseAddA(string str) {
	string res = "";
	for(int i = 0; i < str.length() - 1; i++) {
		res += str[i];
	}
	return res;
}

string reverseFlipAndAddB(string str) {
	string tmp_res = "";
	for(int i = 0; i < str.length() - 1; i++) tmp_res += str[i];

	string res = "";
	for(char letter : tmp_res) res = letter + res;
	return res;
}

void solve() {

	int length = t.length();
	string res = t;
	while(length--) {
		if(res == s) {
			cout << "1";
			return;
		}

		//A인 경우
		if(res[length] == 'A') {
			res = reverseAddA(res);
		}
		else if(res[length] == 'B') {
			res = reverseFlipAndAddB(res);
		}
	}
	cout << "0";
	return;
}

int main() {
	input();
	solve();
}