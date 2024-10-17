#include <bits/stdc++.h>
#define MAX 2001
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[MAX];
vector<int> dest;
priority_queue<pair<int, int>> pq;

bool visited[MAX] = {0,}; // n노드까지 가는 최단거리에서 g-h의 간선을 포함하는지 안하는지에 대한 배열
int dist_S[MAX];
int dist_G[MAX];
int dist_H[MAX];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        dist_S[i] = INF;
        dist_G[i] = INF;
        dist_H[i] = INF;
        graph[i].clear();
        visited[i] = 0;
    }
    dest.clear();
}

void dijkstra(int start, int g, int h, int *dist) {
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int next_dist = dist[cur_node] + graph[cur_node][i].second;
            int next_node = graph[cur_node][i].first;

            if(dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
                visited[next_node] = visited[cur_node];

                if((cur_node == g && next_node == h) || (cur_node == h && next_node == g)) {
                    visited[next_node] = 1;
                }
            }
        }
    }
}

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int n, m, t;
        cin >> n >> m >> t; // 교차로, 도로, 목적지 후보의 개수

        int s, g, h;
        cin >> s >> g >> h; // s : 출발지

        init(n);

        int a, b, d;
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }

        int x;
        for (int i = 0; i < t; i++) {
            cin >> x;
            dest.push_back(x);
        }

        dijkstra(s, g, h, dist_S);
        dijkstra(g, g, h, dist_G);
        dijkstra(h, g, h, dist_H);

        sort(dest.begin(), dest.end());
        for(int num : dest) {
            if(dist_S[num] == dist_S[g] + dist_G[h] + dist_H[num]) cout << num << " ";
            else if(dist_S[num] == dist_S[h] + dist_H[g] + dist_G[num]) cout << num << " ";
        }
        cout << '\n';
    }
}