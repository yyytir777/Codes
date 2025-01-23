// 1766 cpp
#include <bits/stdc++.h>
#define MAX 32001
using namespace std;

int n, m;
int degree[MAX] = {0,};
vector<int> v[MAX];
priority_queue<int> pq;

void print_degree() {
    for(int i = 1; i <= n; i++) {
        cout << degree[i] << " ";
    }
    cout << '\n';
}

void input() {
    cin >> n >> m;

    int s, e;
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        v[s].push_back(e);
        degree[e]++;
    }
}

void bfs() {
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 0) {
            pq.push(-i);
        }
    }


    while(!pq.empty()) {
        int cur_node = -pq.top();
        cout << cur_node << " ";
        pq.pop();

        for(int i = 0; i < v[cur_node].size(); i++) {
            int nxt_node = v[cur_node][i];
            degree[nxt_node]--;
            if(!degree[nxt_node]) {
                pq.push(-nxt_node);
            }
        }
    }
}

void solve() {
    bfs();
}

int main() {
    input();
    solve();
}