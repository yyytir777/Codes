// 1005 cpp
#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321
#define ll long long;
using namespace std;

typedef pair<int, int> Pair;

int n, k;
int d[MAX];
int w;
int parent[MAX];
vector<int> graph[MAX];
priority_queue<Pair> pq; 
int dist[MAX];

void init_parent() {
    for(int i = 1; i <= n; i++) parent[i] = i;
}

void init_dist() {
    for(int i = 1; i <= n; i++) dist[i] = 0;
}

void init_graph() {
    for(int i = 1; i <= n; i++) graph[i].clear();
}

void input() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    init_parent();

    int x, y;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        parent[y] = x;
        graph[x].push_back(y);
    }
    cin >> w;

}

void dijkstra(int start) {
    pq.push({d[start], start});
    dist[start] = d[start];

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] > cur_dist) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int nxt_node = graph[cur_node][i];
            int nxt_dist = cur_dist + d[nxt_node];

            if(dist[nxt_node] < nxt_dist) {
                dist[nxt_node] = nxt_dist;
                pq.push({nxt_dist, nxt_node});
            }
        }
    }
}

int getParent(int num) {
    if(num == parent[num]) return num;

    return getParent(parent[num]);
}
void solve() {
    init_dist();
    int start = getParent(w);
    dijkstra(start);
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