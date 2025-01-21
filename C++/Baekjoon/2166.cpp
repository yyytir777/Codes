// 2166 cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<pair<ll, ll>> v;

void input() {
    cin >> n;

    ll a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
}

void solve() {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        ll element;
        if(i == n - 1) element = v[i].first * v[0].second - v[i].second * v[0].first;
        else element = v[i].first * v[i+1].second - v[i].second * v[i+1].first;
        sum += element;
    }
    double ans = abs(sum) / 2.0;
    printf("%0.1lf", ans);
}

int main() {
    input();
    solve();
    return 0;
}