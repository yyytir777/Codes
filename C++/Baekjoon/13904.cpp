// 13904 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

typedef pair<int, int> Pair;

int n;
int t[MAX] = {0,};
vector<Pair> v;

void input() {
	cin >> n;

	int d, w;
	for(int i = 0; i < n; i++) {
		cin >> d >> w;
		v.push_back({d, w});
	}
}

bool compare(Pair a, Pair b) {
	if(a.second == b.second) return a.first > b.first;
	else return a.second > b.second;
}

void print_v() {
	for(auto node : v) {
		printf("%d %d\n", node.first, node.second);
	}
}

void solve() {
	sort(v.begin(), v.end(), compare);

	// print_v();

	for(int i = 0; i < n; i++) {
		for(int j = v[i].first; j > 0; j--) {
			if(t[j] == 0) {
				t[j] = v[i].second;
				break;
			}
		}
	}

	// for(int i = 1; i <= 1000; i++) printf("%d\n", t[i]);
	int sum = 0;
	for(int i = 0; i <= 1000; i++) {
		sum += t[i];
	}
	cout << sum;
}

int main() {
	input();
	solve();
	return 0;
}