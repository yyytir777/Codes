#include <bits/stdc++.h>
#define MAX_N 1001
#define MAX_M 100001
using namespace std;

bool visited[MAX_M] = {0,};
vector<pair<int, int>> graph[MAX_N];

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
    int cnt = 0, sum = 0;
    visited[1] = 1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;

    for(auto tmp : graph[1]) {
        pq.push({-tmp.first, {start, tmp.second}});
    }

    while(cnt < n - 1) {
        int weight = -pq.top().first;
        int start = pq.top().second.first;
        int end = pq.top().second.second;
        pq.pop();

        if(visited[end]) continue;
        visited[end] = 1;
        cnt++;
        sum += weight;

        for(auto tmp : graph[end]) {
            if(visited[tmp.second]) continue;
            pq.push({-tmp.first, {end, tmp.second}});
        }
    }

    cout << sum;
}