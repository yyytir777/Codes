#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n;
bool visited[MAX] = {0,};
// graph[n] => (x, y)
vector<pair<float, float>> location;
//          {x, {w, y}}
vector<pair<float, int>> graph[MAX];


int main() {
    location.push_back({0,0});
    cin >> n;
    float x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        location.push_back({x, y});
    }

    float dx, dy, w;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if (i == j) continue;

            dx = abs(location[i].first - location[j].first);
            dy = abs(location[i].second - location[j].second);
            w = sqrt(dx * dx + dy * dy);

            graph[i].push_back({w, j});
            graph[j].push_back({w, i});
        }
    }

    int start = 1;
    int cnt = 0;
    float sum = 0;
    visited[1] = 1;
    priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>> pq;

    for(auto tmp : graph[start]) {
        pq.push({-tmp.first, {start, tmp.second}});
    }


    while(cnt < n - 1) {
        float weight = -pq.top().first;
        int start = pq.top().second.first;
        int end = pq.top().second.second;
        pq.pop();

        if(visited[end]) continue;
        visited[end] = 1;
        sum += weight;
        cnt++;

        for(auto tmp : graph[end]) {
            int asdf = tmp.second;
            if(visited[tmp.second]) continue;
            pq.push({-tmp.first, {end, tmp.second}});
        }
    }
    printf("%0.2f", sum);
}