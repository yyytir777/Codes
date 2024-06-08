#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

queue<int> q;
bool graph[MAX][MAX] = {0,};
bool visited[MAX] = {0,};
int cnt = 0;
int N, M;

void bfs(int start) {
    if(visited[start]) return;
    else {
        visited[start] = 1;
        q.push(start);
        cnt++;
    }


    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(int i = 1; i <= N; i++) {
            if(!visited[i] && graph[v][i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    int u, v;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i = 1; i <= N; i++) {
        bfs(i);
    }

    cout << cnt;
}