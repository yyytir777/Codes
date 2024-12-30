#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

// {서류성적, 면접성적}
vector<Pair> grades;

void input() {
	int n;
	cin >> n;

	int a, b;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		grades.push_back({a, b});
	}
}

bool compare(Pair a, Pair b) {
	if(a.second == b.second)
		return a.second < b.second;
	return a.first < b.first;
}

void printVector() {
	for(Pair pair : grades) {
		printf("%d %d\n", pair.first, pair.second);
	}
}

void solve() {
	sort(grades.begin(), grades.end(), compare);
	int cnt = 0;
	int left = grades[0].first;
	int right = grades[0].second;
	for(Pair pair : grades) {
		if(left < pair.first && right < pair.second) {
			continue;
		}
		left = pair.first;
		right = pair.second;
		cnt++;
	}
	cout << cnt << '\n';
}

void init() {
	grades.clear();
}

int main() {
	int tc;
	cin >> tc;

	while(tc--) {
		input();
		solve();
		init();	
	}

	return 0;
}