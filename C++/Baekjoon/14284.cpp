// 14284 cpp
#include <bits/stdc++.h>
#define MAX 5001
#define INF 987654321
using namespace std;

int n, m;
int s, t;
int dist[MAX];
vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>> pq;

void input() {
	cin >> n >> m;

	int a, b, c;
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}

	cin >> s >> t;
}

void dijkstra(int start) {
	dist[start] = 0;
	pq.push({0, start});

	while(!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		// cur_node로 이동한 것보다 기존의 dist가 더 짧을 때
		if(cur_dist > dist[cur_node]) continue;

		for(int i = 0; i < graph[cur_node].size(); i++) {
			int nxt_dist = graph[cur_node][i].second + cur_dist;
			int nxt_node = graph[cur_node][i].first;

			if(nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.push({-nxt_dist, nxt_node});
			}
		}
	} 
}

void init_dist() {
	for(int i = 0; i <= n; i++) {
		dist[i] = INF;
	}
}

void solve() {
	init_dist();
	dijkstra(s);
	cout << dist[t];
}

int main() {
	input();
	solve();
	return 0;
}