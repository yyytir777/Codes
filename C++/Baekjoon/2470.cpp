// 2470 cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int, int> Pair;

int n;
vector<ll> liquid;
vector<pair<ll, Pair>> minCandidate;

void input() {
    cin >> n;

    ll temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        liquid.push_back(temp);
    }
}

bool compare(pair<ll, Pair> a, pair<ll, Pair> b) {
    return a.first < b.first;
}
void solve() {
    sort(liquid.begin(), liquid.end());

    int left = 0, right = liquid.size() - 1;
    ll sum;
    while(left < right) {
        sum = liquid[left] + liquid[right];
        minCandidate.push_back({abs(sum), {liquid[left], liquid[right]}});

        if(sum > 0) right--;
        else left++;
    }

    sort(minCandidate.begin(), minCandidate.end(), compare);
    cout << minCandidate[0].second.first << " " << minCandidate[0].second.second;
}

void print() {
    for(int i = 0; i < n; i++) {
        printf("%lld ", liquid[i]);
    }
}

int main() {
    input();
    solve();
    // print();
    return 0;
}