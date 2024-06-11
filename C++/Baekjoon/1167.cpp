#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
// v[start].push_back( {end, weight} )
vector<pair<int, int>> graph[MAX];
bool visited[MAX] = {0,};
int max_dist = 0, max_node;
int v;

void dfs(int start, int dist) {
    if(visited[start]) return;
    if(max_dist < dist) {
        max_dist = dist;
        max_node = start;
    }

    visited[start] = 1;
    for(int i = 0; i < graph[start].size(); i++) {
        int nxt_vertex = graph[start][i].first;
        int nxt_dist = graph[start][i].second + dist;
        dfs(nxt_vertex, nxt_dist);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v;
    for(int i = 0; i < v; i++) {
        int tmp, vertex;
        cin >> tmp;

        while(true) { // -1을 입력받을 때까지
            cin >> vertex;
            if(vertex == -1) break;

            int w;
            cin >> w;

            graph[tmp].push_back({vertex, w});
            graph[vertex].push_back({tmp, w});
        }
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    max_dist = 0;
    dfs(max_node, 0);
    cout << max_dist;
}