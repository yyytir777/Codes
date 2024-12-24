#include <bits/stdc++.h>
#define MAX 401
#define INF 987654321
using namespace std;

int v, e;

int graph[MAX][MAX];

void input() {
    cin >> v >> e;
    
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            graph[i][j] = INF;
        }
    }

    int a, b, c;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
}

void calDist() {
    for(int k = 1; k <= v; k++) {
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

void print() {
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}

void solve() {
    calDist();

    vector<int> dist;
    for(int i = 1; i <= v; i++) {
        dist.push_back(graph[i][i]);
    }

    sort(dist.begin(), dist.end());
    cout << (dist[0] == INF ? -1 : dist[0]);
}

int main() {
    input();
    solve();
}