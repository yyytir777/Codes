// 10799 cpp
#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;

void input() {
	cin >> str;
}

void solve() {
	int cnt = 0;
	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '(' && str[i+1] == ')') {
			cnt += s.size();
			i++;;
		}
		else if(str[i] == '(') {
			s.push(str[i]);
		}
		else if(str[i] == ')') {
			cnt++;
			s.pop();
		}
	}
	cout << cnt;
}

int main() {
	input();
	solve();
}