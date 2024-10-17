#include <bits/stdc++.h>
#define MAX 50001
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>> pq;
int dist[MAX];
int n, m;

void input() {
    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

void init() {
    for(int i = 1; i <= n; i++) dist[i] = INF;
}

void dijkstra(int start) {
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_dist = dist[cur_node] + graph[cur_node][i].second;

            if(dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }
}

void solution() {
    dijkstra(1);
    cout << dist[n];
}

void solve() {
    input();
    init();
    solution();
}

int main() {
    solve();
    return 0;
}