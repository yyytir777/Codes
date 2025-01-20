// 2268 cpp
#include <bits/stdc++.h>
#define MAX 1000001
#define ll long long
using namespace std;

int n, m;
int arr[MAX] = {0,};
ll tree[MAX * 4];

void init(int n, int start, int end) {
    if(start == end) {
        tree[n] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    init(2 * n, start, mid);
    init(2 * n + 1, mid + 1, end);
    tree[n] = tree[2 * n] + tree[2 * n + 1];
}

ll sum(int queryStart, int queryEnd, int n, int start, int end) {
    if(end < queryStart || queryEnd < start) return 0;
    if(queryStart <= start && end <= queryEnd) return tree[n];

    ll mid = (start + end) / 2;
    ll lsum = sum(queryStart, queryEnd, 2 * n, start, mid);
    ll rsum = sum(queryStart, queryEnd, 2 * n + 1, mid + 1, end);
    return lsum + rsum;
}

void modify(int idx, int target, int n, int start, int end) {
    if(idx < start || end < idx) return;
    if(start == end) {
        tree[n] = target;
        return;
    }

    int mid = (start + end) / 2;
    modify(idx, target, 2 * n, start, mid);
    modify(idx, target, 2 * n + 1, mid + 1, end);
    tree[n] = tree[2 * n] + tree[2 * n + 1];
}

void input() {
    cin >> n >> m;

    init(1, 1, n);

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if(a == 0) {
            if(b > c) cout << sum(c, b, 1, 1, n) << '\n';
            else cout << sum(b, c, 1, 1, n) << '\n';
        }
        else if(a == 1) modify(b, c, 1, 1, n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    return 0;
}