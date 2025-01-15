// 1005 cpp
#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321
#define ll long long;
using namespace std;

typedef pair<int, int> Pair;

int n, k;
int w;
int d[MAX];
int dist[MAX];
int degree[MAX] = {0,};
vector<int> graph[MAX];
queue<int> q;

void init_graph() {
    for(int i = 1; i <= n; i++) graph[i].clear();
}

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
        dist[i] = d[i];
    }

    int x, y;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        degree[y]++;
    }
    cin >> w;

}

void topology() {
    for(int i = 1; i <= n; i++) {
        if(!degree[i]) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if(dist[next] < dist[node] + d[next]) {
                dist[next] = dist[node] + d[next];
            }
            degree[next]--;
            if(!degree[next]) q.push(next);
        }
    }
}

void solve() {
    topology();
    cout << dist[w] << '\n';
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        init_graph();
        input();
        solve();
    }
    
    return 0;
}