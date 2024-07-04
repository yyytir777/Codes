#include <bits/stdc++.h>
#define MAX 501
#define INF 987654321
using namespace std;

long long dist[MAX];
vector<pair<int, pair<int, int>>> graph;
int n, m;

void init_dist() {
    for(int i = 1; i <= n; i++) dist[i] = INF;
}

bool bellman_ford(int start) {
    init_dist();
    dist[start] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int from = graph[j].first;
            int to = graph[j].second.first;
            int weight = graph[j].second.second;

            if(dist[from] == INF) continue;

            if(dist[to] > dist[from] + weight) {
                dist[to] = dist[from] + weight;
                if(i == n) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph.push_back({a, {b, c}});
    }

    bool flag = bellman_ford(1);

    if(flag) {
        printf("-1\n");
        return 0;
    }

    for(int i = 2; i <= n; i++) {
        if(dist[i] == INF) printf("-1\n");
        else printf("%d\n", dist[i]);
    }
    return 0;
}