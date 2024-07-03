#include <bits/stdc++.h>
#define MAX 101
#define INF 987654321
using namespace std;

int m, n;
int graph[MAX][MAX];
int dist[MAX][MAX];

int axis_x[4] = {0, 0, -1, 1};
int axis_y[4] = {1, -1, 0, 0};

void dijkstra(pair<int, int> node) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
    pq.push({0, node});
    dist[node.first][node.second] = 0;

    while(!pq.empty()) {
        int weight = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(dist[x][y] < weight) continue;

        for(int i = 0; i < 4; i++) {
            int nxt_x = x + axis_x[i];
            int nxt_y = y + axis_y[i];
            int nxt_weight = graph[nxt_x][nxt_y] + dist[x][y];

            if(dist[nxt_x][nxt_y] > nxt_weight) {
                dist[nxt_x][nxt_y] = nxt_weight;
                pq.push({-nxt_weight, {nxt_x, nxt_y}});
            }
        }
    }
}

int main() {
    cin >> m >> n;

    string tmp;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;

        for(int j = 1; j <= m; j++) {
            graph[i][j] = int (tmp[j-1] - 48);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dist[i][j] = INF;
        }
    }

    dijkstra({1,1});

    cout << dist[n][m];
}