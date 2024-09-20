#include <bits/stdc++.h>
#define MAX 51
#define INF 987654321
using namespace std;

int n, s, e, m;
vector<pair<int, pair<int, int>>> graph;
int profit[MAX];
long long dist[MAX];
bool visited[MAX] = {0,};
queue<int> q;

void init_dist() {
    for(int i = 0; i < n; i++) dist[i] = INF;
}

bool check(int start) {
    visited[start] = 1;
    q.push(start);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        if(v == e) return true;
        for(int i = 0; i < m; i++) {
            if(v != graph[i].first) continue;
            if(visited[graph[i].second.first]) continue;
            visited[graph[i].second.first] = 1;
            q.push(graph[i].second.first);
        }
    }
    return false;
}

bool bellman_ford(int s) {
    dist[s] = -profit[s];

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            int from = graph[j].first;
            int to = graph[j].second.first;
            int weight = graph[j].second.second - profit[to];

            if(dist[from] == INF) continue;

            if(dist[to] > dist[from] + weight) {
                dist[to] = dist[from] + weight;
                if(i == n && check(to)) return true;
            }
        }
    }
    return false;
}

// 나가는 돈을 양수로, 들어오는 돈을 음수로해야 벨만포드 알고리즘에서 최솟값을 선택하여
// 결국엔 돈 액수의 최댓값을 리턴함.

int main() {
    cin >> n >> s >> e >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph.push_back({a, {b, c}});
    }

    for(int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    init_dist();

    bool flag = bellman_ford(s);

    if(flag) printf("Gee\n");
    else if(dist[e] == INF) printf("gg\n");
    else printf("%lld\n", -dist[e]);
}