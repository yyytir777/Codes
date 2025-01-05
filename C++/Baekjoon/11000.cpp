// 11000 cpp
#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

typedef pair<int, int> Pair;


int n;
vector<Pair> v;
int rooms[MAX];

void input() {
    cin >> n;
    int s, t;
    for(int i = 0; i < n; i++) {
        cin >> s >> t;
        v.push_back({s, t});
    }
}

void solve() {
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    
    pq.push(v[0].second);
    for(int i = 1; i < n; i++) {
        pq.push(v[i].second);
        if(v[i].first >= pq.top()) pq.pop();
    }

    cout << pq.size();
}

int main() {
    input();
    solve();
    return 0;
}