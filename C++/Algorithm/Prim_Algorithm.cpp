#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

bool isSelected[MAX] = {0,};
vector<pair<int, int>> adj[MAX];

int v, e;

int main() {
    cin >> v >> e;

    int a, b, c;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int start = 1;
    int cnt = 0, sum = 0;
    isSelected[start] = 1;
    //                  weight, pair<start, end>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for(auto tmp : adj[start]) {
        pq.push({tmp.first, {start, tmp.second}});
    }

    while(cnt < v - 1) {
        int w = pq.top().first;
        int start = pq.top().second.first;
        int end = pq.top().second.second;
        pq.pop();

        if(isSelected[end]) continue;
        isSelected[end] = 1;
        sum += w;
        cnt++;

        for(auto tmp : adj[end]) {
            if (isSelected[tmp.second]) continue;
            pq.push({tmp.first, {end, tmp.second}});
        }
    }
    cout << sum;
}