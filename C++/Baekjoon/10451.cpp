// 10451 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
int arr[MAX];
bool visited[MAX] = {0,};

void init() {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}

bool bfs(int node) {
	visited[node] = 1;

	int iter = 0;
	while(iter <= n) {
		node = arr[node];
		if(visited[node]) return true;

		visited[node] = 1;
		iter++;
	}
	return false;
}

void input() {
	cin >> n;
}

void solve() {
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(visited[i]) continue;

		if(bfs(i)) {
			cnt++;
		}
	}
	cout << cnt << '\n';
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		init();
		input();
		solve();
	}
	return 0;
}