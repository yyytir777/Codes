#include <bits/stdc++.h>
#define MAX 510
using namespace std;

vector<int> graph[MAX];
int visited[MAX] = {0,};
bool cycleFlag = 0;
int cnt = 0;

void dfs(int start, int prev) {
    visited[start] = 1;
    for(int adj : graph[start]) {
        if(adj == prev) continue;
        if(visited[adj] && prev != adj) cycleFlag = 1;
        else dfs(adj, start);
    }
}

int main() {
    int n, m;
    int i = 1;
    while(i) { 
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int j = 0; j <= n; j++) {
            graph[j].clear();
        }
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        int start, end;
        for(int j = 0; j < m; j++) {
            cin >> start >> end;
            graph[start].push_back(end);
            graph[end].push_back(start);
        }

        for(int j = 1; j <= n; j++) {
            if(!visited[j]) {
                cycleFlag = 0;
                dfs(j, -1);
                if(!cycleFlag) cnt++;
            }
        }

        cout << "Case " << i << ": ";
        if(cnt == 0) cout << "No trees.\n";
        else if(cnt == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << cnt << " trees.\n";
        i++;

    }
    return 0;
}