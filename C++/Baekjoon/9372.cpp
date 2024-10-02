#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int t;
vector<int> graph[MAX];
bool visited[MAX] = {0,};

void init_visited(int n) {
    for(int i = 0; i <= n; i++) {
        visited[i] = 0;
    }
}

int bfs(int start) {
    int cnt = 0;
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];

            if(!visited[next]) {
                visited[next] = 1;
                cnt++;
                q.push(next);
            }
        }
    }
    return cnt;
}

int main() {
    cin >> t;

    int n, m;
    while(t--) {
        cin >> n >> m;

        int a, b;
        init_visited(n);
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        cout << bfs(1) << '\n';
    }
}