#include <bits/stdc++.h>
#define MAX 300001
using namespace std;

typedef pair<int, int> Pair;

int Answer, n;
int node[MAX] = {0,};
bool visited[MAX] = {0,};

vector<int> cnts;
vector<int> graph[MAX];


void init() {
	cnts.clear();
	for(int i = 1; i <= n; i++) {
		node[i] = 0;
		visited[i] = 0;
		graph[i].clear();
	}
}

void input() {
	cin >> n;

	int s, e;
	for(int i = 0; i <= n; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
		node[s]++, node[e]++;
	}
}

void dfs(int idx, int cnt) {
	for (int i = 0; i < graph[idx].size(); i++) {
		int nxt = graph[idx][i];
		if(visited[nxt]) continue;
		if (node[nxt] == 3) {
			cnts.push_back(cnt + 1);
			continue;
		}

		visited[nxt] = 1;
		dfs(nxt, cnt + 1);	
		visited[nxt] = 0;
	}
}

void solve() {
	int start;
	for(int i = 1; i <= n; i++) {
		if(node[i] == 3) start = i;
	}

	visited[start] = 1;
	dfs(start, 0);

	for(int cnt : cnts) {
		cout << cnt << " ";
		if(cnt == 1) continue;

		Answer += cnt * (cnt - 1) / 2;
	}
	cout << '\n';
}

int main(int argc, char** argv) {
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {

		Answer = 0;

		init();
		input();
		solve();

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}