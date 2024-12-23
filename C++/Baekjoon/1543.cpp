#include <bits/stdc++.h>
using namespace std;

string str, target;
int cnt = 0;

void input() {
	getline(cin, str);
	getline(cin, target);
}

bool isEqual(int idx) {
	for(int i = 0; i < target.length(); i++) {
		if(str[idx] != target[i]) {
			return false;
		}
		idx++;
	}
	return true;
}

void solve() {
	int i = 0;
	while(i <= str.length()) {
		if(isEqual(i)) {
			cnt++;
			i += target.length();
		}
		else {
			i++;
		}
	}
	cout << cnt;
}

int main() {
	input();
	solve();
	return 0;
}