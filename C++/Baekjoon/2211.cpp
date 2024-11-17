#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321
using namespace std;

int n, m, cnt = 0;
int dist[MAX];
vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>> pq;
set<pair<int ,int>> ans;

void input() {
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < n; i++) {
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
        int cur_dist = pq.top().first;
        pq.pop();

        if(cur_dist > dist[cur_node]) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int nxt_node = graph[cur_node][i].first;
            int nxt_dist = cur_dist + graph[cur_node][i].second;

            if(nxt_dist < dist[nxt_node]) {
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
                cur_node > nxt_node ? ans.insert({nxt_node, cur_node}) : ans.insert({cur_node, nxt_node});
                cnt++;
            }
        }
    }
}

void solve() {
    dijkstra(1);

    printf("%d\n", cnt);
    for(auto num : ans) {
        printf("%d %d\n", num.first, num.second);
    }
}

int main() {
    input();
    init();
    solve();
}