#include <bits/stdc++.h>
#define MAX 510
#define INF 987654321
using namespace std;

vector<pair<int, pair<int, int>>> graph;
int dist[MAX];
int n, m, w;

bool bellman_ford(int start) {
    dist[start] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < graph.size(); j++) {
            int from = graph[j].first;
            int to = graph[j].second.first;
            int cost = graph[j].second.second;

            if(dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
                if(i == n) return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m >> w;

    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    int s, e, t;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        graph.push_back({s, {e, t}});
        graph.push_back({e, {s, t}});
    }

    for(int i = 0; i < w; i++) {
        cin >> s >> e >> t;
        graph.push_back({s, {e, -t}});
    }


    if(bellman_ford(n)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int tc;
    cin >> tc;

    while(tc--) {
        graph.clear();
        solve();
    }
}