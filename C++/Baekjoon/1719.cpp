#include <bits/stdc++.h>
#define MAX 201
#define INF 987654321
using namespace std;

int n, m;
int dist[MAX];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> graph[MAX];

void input() {
    cin >> n >> m;

    int s, e, w;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }
}

void init() {
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
    }
}

void dijkstra(int start) {
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if(cur_dist > dist[cur_node]) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int nxt_node = graph[cur_node][i].first;
            int nxt_dist = dist[cur_node] + graph[cur_node][i].second;

            if(nxt_dist < dist[nxt_node]) {
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }
}

void solve() {
    dijkstra(1);

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}

int main() {
    input();
    init();
    solve();
}