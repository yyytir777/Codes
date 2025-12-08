#include <algorithm>
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int Answer = 0;
int n, l;
bool visited[MAX];

vector<int> a, b;

void input() {
	cin >> n >> l;

	int tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}
}

void init() {
	a.clear();
	b.clear();
	for(int i = 0; i < n; i++) {
		visited[i] = 0;
	}

	Answer = 0;
}

bool compare(int a1, int a2) {
	return a1 > a2;
}

void solve() {
	Answer = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	for(int i = 0; i < n; i++) {
		// l - a[i]와 같거나 클 때의 iter 값 : l - a[i]보다 작은 값을 구해야하므로 iter--를 사용
		auto iter = lower_bound(b.begin(), b.end(), l - a[i]);

		if(iter == b.end()) {
			Answer = -1;
			return;
		}

		while(iter != b.end()) {
			int idx = distance(b.begin(), iter);
			int diff = abs(a[i] - *iter);

			printf("idx : %d, diff : %d\n", idx, diff);

			if(diff <= l && !visited[idx]) {
				visited[idx] = 1;
				Answer = max(Answer, diff);
				break;
			}
			iter++;
		}
	}
}

int main() {
	int t; cin >> t;

	for(int tc = 1; tc <= t; tc++) {
		init();
		input();
		solve();

		printf("Case #%d\n", tc);
		printf("%d\n", Answer);
	}
	
	return 0;
}