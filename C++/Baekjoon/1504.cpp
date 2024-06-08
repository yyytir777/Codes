#include <bits/stdc++.h>
#define MAX 801
#define INF 987654321
using namespace std;

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> graph[MAX];
long long dist[MAX];
long long n, e;

void init() {
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
}

void dijkstra(long long start) {
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        long long cur_node = pq.top().second;
        long long cur_dist = -pq.top().first;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(long long i = 0; i < graph[cur_node].size(); i++) {
            long long nxt_node = graph[cur_node][i].first;
            long long nxt_dist = graph[cur_node][i].second + cur_dist;

            if(dist[nxt_node] > nxt_dist) {
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }
}

int main() {
    cin >> n >> e;

    long long a, b, c;
    for(long long i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    long long v1, v2;
    cin >> v1 >> v2;

    long long result1 = 0;

    init(); // dist 초기화
    dijkstra(1);
    result1 += dist[v1];
    if(dist[v1] == INF) {
        cout << -1;
        return 0;
    }

    init();
    dijkstra(v1);
    result1 += dist[v2];
    if(dist[v2] == INF) {
        cout << -1;
        return 0;
    }

    init();
    dijkstra(v2);
    result1 += dist[n];
    if(dist[n] == INF) {
        cout << -1;
        return 0;
    }

    long long result2 = 0;

    init(); // dist 초기화
    dijkstra(1);
    result2 += dist[v2];
    if(dist[v2] == INF) {
        cout << -1;
        return 0;
    }

    init();
    dijkstra(v2);
    result2 += dist[v1];
    if(dist[v1] == INF) {
        cout << -1;
        return 0;
    }

    init();
    dijkstra(v1);
    result2 += dist[n];
    if(dist[n] == INF) {
        cout << -1;
        return 0;
    }

    int result = min(result1, result2);
    cout << result;
}