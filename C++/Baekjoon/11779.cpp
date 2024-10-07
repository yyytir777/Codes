#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1001
using namespace std;

vector<pair<int, int>> graph[MAX]; // v[from] = {to, dist}
priority_queue<pair<int, int>> pq;
int parent[MAX];
int dist[MAX];

void init_parent(int n) {
    for(int i = 1; i <= n; i++) parent[i] = -1;
}

void init_dist(int n) {
    for(int i = 1; i <= n; i++) dist[i] = INF;
}

void dijkstra(int start) {
    dist[start] = 0;
    parent[start] = -1;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_dist = dist[cur_node] + graph[cur_node][i].second;
            int next_node = graph[cur_node][i].first;

            if(dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
                parent[next_node] = cur_node;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    int from, to;
    cin >> from >> to;

    init_dist(n);
    init_parent(n);
    dijkstra(from);

    cout << dist[to] << '\n';

    int trace = to;
    stack<int> s;
    while(true) {
        s.push(trace);
        if(parent[trace] == -1) break;
        trace = parent[trace];
    }

    cout << s.size() << '\n';

    while(!s.empty()) {
        cout << s.top() <<" ";
        s.pop();
    }

    return 0;
}