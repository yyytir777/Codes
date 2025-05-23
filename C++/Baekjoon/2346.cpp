// 2346 cpp
#include <bits/stdc++.h>
using namespace std;

int n;
deque<pair<int, int>> balloon;

void input() {
	cin >> n;
	int tmp;
	for(int i = 1; i <= n; i++) {
		cin >> tmp;
		balloon.push_back({tmp, i});
	}
}

void solve() {
	while(!balloon.empty()) {
		pair<int, int> node = balloon.front();
		balloon.pop_front();
		cout << node.second << " ";

		if(node.first > 0) {
			for(int i = 1; i < node.first && !balloon.empty(); i++) {
				balloon.push_back(balloon.front());
				balloon.pop_front();
			}
		} else {
			for(int i = 0; i < -node.first && !balloon.empty(); i++) {
				balloon.push_front(balloon.back());
				balloon.pop_back();	
			}
		}
	}
}

int main() {
	input();
	solve();
	return 0;
}