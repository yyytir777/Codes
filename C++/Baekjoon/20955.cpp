#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
bool visited[MAX] = {0,};
int n, m, cnt = 0;
bool cycleFlag = 1;


// 0 : cycle 있는 그래프 // 1 : cycle 없는 그래프
bool dfs(int start, int parent) {
    cnt++;
    visited[start] = 1;

    if(graph[start].size() == 0) return 1;

    for(int adj : graph[start]) {
        if(adj == parent) continue;
        if(visited[adj] && parent != adj) cycleFlag = 0;
        else dfs(adj, start);
    }
    return cycleFlag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt_non_cycle = 0, cnt_cycle = 0;
    for(int i = 0; i < n; i++) {
        cycleFlag = 1, cnt = 1;
        if(visited[i]) continue;
        bool flag = dfs(i, -1);
        if(flag) cnt_non_cycle++;
        else cnt_cycle++;
    }
    cnt_non_cycle--;
    // cout << "cnt_non_cycle : " << cnt_non_cycle << '\n';
    // cout << "cnt_cycle : " << cnt_cycle << '\n';
    cout << (cnt_non_cycle - 1) + 2 * (cnt_cycle);
}

// 연산 횟수 : cycle있는 그래프 / cycle 없는 그래프
// size(cycle없는 그래프) - 1 + size(cycle있는 그래프) * 2
