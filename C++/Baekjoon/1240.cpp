#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

//          graph[from].push_back({to, w});
vector<pair<int, int>> graph[MAX];
bool visited[MAX] = {0,};
int n, m, total_dist;

void dfs(int start, int end, int dist) {
    if(start == end) {
        total_dist = dist;
        return;
    }

    visited[start] = 1;

    for(auto node : graph[start]) {
        int adj_node = node.first;
        int adj_dist = node.second;

        if(visited[adj_node]) continue;

        dist += adj_dist;
        dfs(adj_node, end, dist);
        dist -= adj_dist;
    }
}

int main() {
    cin >> n >> m;

    int from, to, w;
    for(int i = 0; i < n - 1; i++) {
        cin >> from >> to >> w;
        graph[from].push_back({ to, w });
        graph[to].push_back({ from, w });
    }

    int start, end;
    for(int i = 0; i < m; i++) {
        cin >> start >> end;
        dfs(start, end, 0);
        cout << total_dist << '\n';
        memset(visited, 0, sizeof(visited));
    }
}