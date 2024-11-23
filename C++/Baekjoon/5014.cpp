#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int f, s, g, u, d;
bool visited[MAX] = {0,};
int dp[MAX] = {0,};
queue<int> q;

void input() {
    cin >> f >> s >> g >> u >> d;
}

void bfs(int start) {
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int cur_floor = q.front();
        q.pop();

        int nxt_up_floor = cur_floor + u;
        if(nxt_up_floor > 0 && nxt_up_floor <= f) {
            if(!visited[nxt_up_floor]) {
                q.push(nxt_up_floor);
                visited[nxt_up_floor] = 1;
                dp[nxt_up_floor] = dp[cur_floor] + 1;
            }
            
        }

        int nxt_down_floor = cur_floor - d;
        if(nxt_down_floor > 0 && nxt_down_floor <= f) {
            if(!visited[nxt_down_floor]) {
                q.push(nxt_down_floor);
                visited[nxt_down_floor] = 1;
                dp[nxt_down_floor] = dp[cur_floor] + 1;
            }
        }
    }
}

void solve() {
    bfs(s);

    if(visited[g]) cout << dp[g];
    else cout << "use the stairs";
}

int main() {
    input();
    solve();
}