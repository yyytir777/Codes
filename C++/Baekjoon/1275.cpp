// 1275 cpp
#include <bits/stdc++.h>
#define MAX 100001
#define ll long long
using namespace std;


ll n, q;
ll arr[MAX];
ll tree[MAX * 4];

void input() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void init_tree(int n, int start, int end) {
    if(start == end) {
        tree[n] = arr[start];
        return;
    }

    int m = (start + end) / 2;
    init_tree(2 * n, start, m);
    init_tree(2 * n + 1, m + 1, end);
    tree[n] = tree[2 * n] + tree[2 * n + 1];
}

ll query(int left, int right, int n, int start, int end) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[n];

    int mid = (start + end) / 2;
    ll lsum = query(left, right, 2 * n, start, mid);
    ll rsum = query(left, right, 2 * n + 1, mid + 1, end);
    return lsum + rsum;
}

void update(int idx, ll t, int n, int start, int end) {
    if(end < idx || idx < start) return;
    if(start == end) {
        tree[n] = t;
        return;
    }

    int mid = (start + end) / 2;
    update(idx, t, 2 * n, start, mid);
    update(idx, t, 2 * n + 1, mid + 1, end);
    tree[n] = tree[2 * n] + tree[2 * n + 1];
}

void prll_tree() {
    cout << '\n';
    for(int i = 1; i < 10; i++) cout << tree[i] << " ";
    cout << '\n';
}

void solve() {
    init_tree(1, 1, n);
    ll x, y, a, b;
    for(int i = 0; i < q; i++) {
        // [x,y]까지 합을 구하고 a번째 수를 b로 변경
        cin >> x >> y >> a >> b;

        if(x <= y) cout << query(x, y, 1, 1, n) << '\n';
        else cout << query(y, x, 1, 1, n) << '\n';
        update(a, b, 1, 1, n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    return 0;
}