#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1001
using namespace std;

int n, m, x;
vector<int> v;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
priority_queue<pair<int, int>> pq;

bool compare(int a, int b) {
    if(a > b) return true;
    return false;
}

void dijkstra(int start) {
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int nxt_dist = graph[cur_node][i].second + cur_dist;
            int nxt_node = graph[cur_node][i].first;

            if(dist[nxt_node] > nxt_dist) {
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }
}

void init() {
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
}

int main() {
    cin >> n >> m >> x;

    int a, b, t;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
    }


    for(int i = 1; i <= n; i++) {
        int result = 0;
    
        init();
        dijkstra(i);
        result += dist[x];

        init();
        dijkstra(x);
        result += dist[i];

        v.push_back(result);
    }

    sort(v.begin(), v.end(), compare);

    cout << v[0];
}