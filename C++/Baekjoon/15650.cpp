#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[9];

void combination(int start, int m, vector<int> v) {
    if(m == M) {
        sort(v.begin(), v.end());
        for(int tmp : v) {
            cout << tmp << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i = start; i <= N; i++) {
        v.push_back(arr[i]);
        combination(i + 1, m + 1, v);
        v.pop_back();
    }
}

void solve() {
    vector<int> v;
    combination(1, 0, v);
}

int main() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    solve();
}