// 12851 cpp
#include <bits/stdc++.h>
#define MAX 100001
#define INF 987654321
using namespace std;

int n, k;
int graph[MAX];
bool visited[MAX] = {0,};
queue<pair<int, int>> q; // {node, time}

int min_dist = INF;
int cnt = 0;

void input() {
    cin >> n >> k;
}

void bfs(int start) {
    bool first = true;
    q.push({start, 0});
    visited[start] = 1;
    
    while(!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        visited[node] = 1;
        q.pop();

        if(node == k) {
            //처음 도달했을 때
            if(first) {
                first = !first;
                min_dist = dist;
                cnt++;
            }

            // 처음 도달한게 아닐 때
            else if(!first && min_dist == dist){
                cnt++;
            }
        }

        for(int next_node : {node - 1, node + 1, node * 2}) {
            if(next_node >= 0 && next_node <= 100000 && !visited[next_node]) {
                q.push({next_node, dist + 1});
            }
        }
    }
}

void test() {
}

void solve() {
    bfs(n);
    cout << min_dist << '\n' << cnt;
}

int main() {
    input();
    solve();
    return 0;
}