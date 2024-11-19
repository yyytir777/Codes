#include <bits/stdc++.h>
#define MAX 20001
using namespace std;

int v, e;
int visited[MAX];
vector<int> graph[MAX];
queue<int> q;

void bfs(int start) {
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int cur_node = q.front();
        q.pop();

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int nxt_node = graph[cur_node][i];
            if(visited[nxt_node] == 0) {
                visited[nxt_node] = -visited[cur_node];
                q.push(nxt_node);
            }
        }
    }
}

void input() {
    cin >> v >> e;

    int start, end;
    for(int i = 0; i < e; i++) {
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
}

void init() {
    for(int i = 1; i <= MAX; i++) {
        visited[i] = 0;
        graph[i].clear();
    }
}

void solve() {
    for(int i = 1; i <= v; i++) {
        if(visited[i] == 0) {
            bfs(i);
        }
    }

    for(int i = 1; i <= v; i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            int node = graph[i][j];
            if(visited[i] == visited[node]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    return;
}

int main() {
    int k; cin >> k;

    while(k--) {
        init();
        input();
        solve();
    }
}