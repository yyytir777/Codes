#include <bits/stdc++.h>
#define INF 987654321
#define MAX 101
using namespace std;

vector<pair<int, int>> graph[MAX]; // graph[from] = {to, dist};
priority_queue<pair<int, int>> pq;
int items[MAX];
int dist[MAX];
int max_item = 0;

void init_dist(int n) {
    for(int i = 1; i <= n; i++) dist[i] = INF;
}

void dijkstra(int start) {
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_dist = graph[cur_node][i].second + dist[cur_node];
            int next_node = graph[cur_node][i].first;

            if(next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) cin >> items[i];

    int a, b, l;
    for(int i = 1; i <= r; i++) {
        cin >> a >> b >> l;
        graph[a].push_back({b,l});
        graph[b].push_back({a,l});
    }

    for(int i = 1; i <= n; i++) {
        init_dist(n);
        dijkstra(i);

        int sum_items = 0;
        for(int j = 1; j <= n; j++) {
            if(dist[j] <= m) sum_items += items[j];
        }
        max_item = max(max_item, sum_items);
    }

    cout << max_item;
    return 0;
}