#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
map<int, int> parent; // -> key : value = (child : parent)
bool visited[MAX] = {0,};

void dfs(int start) { 
    if(visited[start]) return;
    visited[start] = 1;

    for(int i = 0; i < graph[start].size(); i++) {
        int nxt_node = graph[start][i];
        parent.insert({nxt_node, start});
        dfs(nxt_node);
    }
}

int main() {
    int n;
    cin >> n;

    int from, to;
    for(int i = 0; i < n - 1; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    dfs(1);

    for(int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
}