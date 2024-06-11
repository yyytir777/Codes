#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
//          graph[from].push_back({to, w})
vector<pair<int, int>> graph[MAX];
bool visited[MAX ]= {0,};
int max_dist = 0, max_node;

void dfs(int start, int dist) {
    if(visited[start]) return;

    if(max_dist  < dist) {
        max_dist = dist;
        max_node = start;
    }

    visited[start] = 1;

    for(int i = 0; i < graph[start].size(); i++) {
        int nxt_node = graph[start][i].first;
        int nxt_dist = graph[start][i].second + dist;

        dfs(nxt_node, nxt_dist);
    }
}

int main() {
    int n;
    cin >> n;

    int from, to, w;
    for(int i = 0; i < n - 1; i++) {
        cin >> from >> to >> w;

        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    max_dist = 0;
    dfs(max_node, 0);

    cout << max_dist;
    return 0;
}