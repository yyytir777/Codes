#include <bits/stdc++.h>
#define MAX 10001
#define INF 987654321
using namespace std;

int n, d;
int dp[MAX];
vector<pair<int, int>> graph[MAX];

void input() {
    cin >> n >> d;

    int s, e, w;
    for(int i = 0; i < n; i++) {
        cin >> s >> e >> w;
        if(e - s <= w || e > d) continue;
        graph[e].push_back({s, w});
    }
}


void solve() {
    dp[0] = 0;
    for(int i = 1; i <= d; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = 0; j < graph[i].size(); j++) {
            dp[i] = min(dp[i], dp[graph[i][j].first] + graph[i][j].second);
        }
    }
    cout << dp[d];
}

int main() {
    input();
    solve();
}