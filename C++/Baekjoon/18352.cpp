#include <bits/stdc++.h>
#define MAX 300001
#define INF 987654321
using namespace std;

int dist[MAX];
vector<int> v[MAX];

priority_queue<pair<int, int>> pq;

void init_dist(int n) {
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
}

void dijkstra(int start) {
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(int i = 0; i < v[cur_node].size(); i++) {
            int next_node = v[cur_node][i];
            int next_dist = dist[cur_node] + 1;

            if(dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }
}

int main() {
    int n, m, k, x;
    cin >> n >> m >> k >> x;

    int from, to;
    for(int i = 0; i < m; i++) {
        cin >> from >> to;
        v[from].push_back(to);
    }

    init_dist(n);
    dijkstra(x);

    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == k) {
            cout << i << '\n';
            flag = 1;
        }
    }

    if(!flag) cout << "-1";

    return 0;
}