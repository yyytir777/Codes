// 1021 cpp
#include <bits/stdc++.h>
using namespace std;

deque<int> d;
vector<int> nodes;
int n, m;

void input() {
	cin >> n >> m;

	for(int i = 1; i <= n; i++) d.push_back(i);

	int tmp;
	for(int i = 0; i < m; i++) {
		cin >> tmp;
		nodes.push_back(tmp);
	}
}

void move(int direction) {
	if(direction == 1) { // 오른쪽으로 이동
		d.push_front(d.back());
		d.pop_back();
	}
	else { // 왼쪽으로 이동
		d.push_back(d.front());
		d.pop_front();
	}
}
	
void solve() {

	int idx, cnt = 0;
	for(int node : nodes) {
		// find idx;
		for(int i = 0; i < d.size(); i++) {
			if(d[i] == node) {
				idx = i;
				break;
			}
		}

		// 앞의 element와 가까움 (왼쪽 이동)
		if(idx <= d.size() / 2) {
			while(true) {
				if(d.front() == node) {
					d.pop_front();
					break;
				}
				move(-1);
				cnt++;
			}
		}
		else { // 오른쪽 이동
			while(true) {
				if(d.front() == node) {
					d.pop_front();
					break;
				}
				move(1);
				cnt++;
			}		
		}
	}

	cout << cnt;
}

int main() {
	input();
	solve();
	return 0;
}