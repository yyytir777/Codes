#include <iostream>
#include <queue>
#define N 1010
#define INF 100000000
using namespace std;

int graph[N][N] = {0,};
bool visited[N] = {0,};
int dist[N];
int n, m;

int findNxtNode() {
    int min_dist = INF;
    int min_idx = -1;

    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        if(dist[i] < min_dist) {
            min_dist = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void dijkstra(int start) {
    for(int i = 1; i <= n; i++) {
        dist[i] = graph[start][i];
    }

    visited[start] = true;

    for(int i = 0; i < n; i++) {
        int nxt_node = findNxtNode();
        visited[nxt_node] = true;

        for(int j = 1; j <= n; j++) {
            if(visited[j]) continue;
            if(dist[j] > dist[nxt_node] + graph[nxt_node][j]) dist[j] = dist[nxt_node] + graph[nxt_node][j];
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    int from, to, cost;
    for(int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        graph[from][to] = cost;
        graph[i+1][i+1] = 0;
    }
    
    int start, dest;
    cin >> start >> dest;

    for(int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    
    dijkstra(start);

    cout << dist[dest];
}