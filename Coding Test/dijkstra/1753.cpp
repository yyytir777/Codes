#include <iostream>
#include <vector>
#include <queue>
#define MAX 300001
#define INF 1000000
using namespace std;
//                 <노드번호, 거리>
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> graph[MAX];
int dist[20001];
int V, E, K;

void input(){

}

void dijkstra(int start) {
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(int i = 0; i < graph[cur_node].size(); i++) {
            int nxt_node = graph[cur_node][i].first;
            int nxt_dist = graph[cur_node][i].second + cur_dist;

            if(dist[nxt_node] > nxt_dist) {
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    int u, v, w;
    for(int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }

    for(int i = 0; i <= V; i++) {
        dist[i] = INF;
    }

    dijkstra(K);

    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF) 
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
    return 0;
}