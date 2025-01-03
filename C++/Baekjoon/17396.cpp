// 17396 cpp
#include <bits/stdc++.h>
#define MAX 100001
#define ll long long int
using namespace std;

typedef pair<ll, ll> Pair;

const long long INF = LLONG_MAX;
ll n, m;
bool sights[MAX]; // 0이면 보이지 않음 1이면 보임
ll dist[MAX];
vector<pair<ll, ll>> graph[MAX];
priority_queue<pair<ll, ll>> pq;

void input() {
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        cin >> sights[i];
    }

    ll a, b, t;
    for(ll i = 0; i < m; i++) {
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, t});
    }
}

void print_dist() {
    for(ll i = 0 ; i < n; i++) cout << dist[i] << " " ;
}

void print_sights() {
    for(ll i = 0 ; i < n; i++) cout << sights[i] << " " ;
}

void dijkstra() {
    ll start = 0;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        ll cur_dist = -pq.top().first;
        ll cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(ll i = 0; i < graph[cur_node].size(); i++) {
            ll nxt_dist = dist[cur_node] + graph[cur_node][i].second;
            ll nxt_node = graph[cur_node][i].first;

            if(sights[nxt_node] && nxt_node != n-1) continue;

            if(dist[nxt_node] > nxt_dist) {
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }

    if(dist[n-1] == INF) cout << "-1";
    else cout << dist[n-1];
}

void init_dist() {
    for(ll i = 0; i < n; i++) dist[i] = INF;
}

void solve() {
    init_dist();
    dijkstra();
}

int main() {
    input();
    solve();
    return 0;
}