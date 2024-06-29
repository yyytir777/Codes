#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<pair<int, int>> graph[MAX];
bool visited[MAX] = {0,};
int n, m;

int main() {
    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    int start = 1;
    int cnt = 0, sum = 0, max_weight = 0;
    visited[start] = 1;
                    //weight, <start, end>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;

    for(auto tmp : graph[start]) pq.push({-tmp.first, {start, tmp.second}});

    while(cnt < n - 1) {
        auto tmp = pq.top();
        pq.pop();
        int weight = -tmp.first;
        max_weight = max(weight, max_weight);
        int start = tmp.second.first;
        int end = tmp.second.second;

        if(visited[end]) continue;
        visited[end] = 1;
        sum += weight;
        cnt++;

        for(auto node : graph[end]) {
            pq.push({-node.first, {end, node.second}});
        }
    }
    // cout << "sum : " << sum << '\n';
    // cout << "max_weight : " << max_weight << '\n';
    cout << sum - max_weight;
}