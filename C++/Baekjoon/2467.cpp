// 2467 cpp
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n;
vector<int> v(MAX);

void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

void solve() {
    pair<int, int> ans;
    int start = 0, end = n-1, minSum = INT_MAX, sum;
    while(start < end && end < n) {
        int sum = v[start] + v[end];

        if(minSum > abs(sum)) {
            minSum = abs(sum);
            ans = {start, end};
        }

        if(sum < 0) start++;
        else if(sum > 0) end--;
        else {
            ans = {start, end};
            break;
        }
    }
    cout << v[ans.first] << " " << v[ans.second];
}

int main() {
    input();
    solve();
    return 0;
}