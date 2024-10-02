#include <bits/stdc++.h>
#define MAX 101
using namespace std;

vector<int> graph[MAX]; // -> i가 1, 2, 3과 부모자식관계를 맺었다면, v[i] = {1, 2, 3}
int dist[MAX] = {0,};
bool visited[MAX] ={0,};
queue<int> q;

int bfs(int start, int end) {
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int cur_node = q.front();
        q.pop();

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i];
            if(visited[next_node] == 0) {
                visited[next_node] = 1;
                q.push(next_node);
                dist[next_node] = dist[cur_node] + 1;
            }
        }
    }

    if(dist[end] == 0) return -1;
    else return dist[end];
}

int main() {
    int n;
    cin >> n;

    int start, end;
    cin >> start >> end;

    int m;
    cin >> m;

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << bfs(start, end);
    return 0;
}