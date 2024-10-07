#include <bits/stdc++.h>
#define MAX 10001
#define INF 987654321
using namespace std;

vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>> pq;

int dist[MAX];

void init_dist(int n) {
    for(int i = 1; i <= n; i++) dist[i] = INF;
}

void dijkstra(int start) {
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if(dist[cur_dist] < cur_dist) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_dist = graph[cur_node][i].second + dist[cur_node];

            if(dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }
}

int main() {
    int tc; cin >> tc;

    int n, d, c;
    while(tc--) {
        cin >> n >> d >> c;

        int a, b, s;
        for(int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        init_dist(n);
        dijkstra(c);

        int max_dist = 0, cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] != INF) {
                cnt++;
                max_dist = max(max_dist, dist[i]);
            }
        }

        cout << cnt << ' ' << max_dist << '\n';
    }
    return 0;
}