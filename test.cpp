// 14438 cpp
#include <bits/stdc++.h>
#define MAX 100001
#define INF 2000000000
using namespace std;

int n, m;
int arr[MAX];
int tree[MAX * 4 + 1];

void init_tree(int n, int s, int e) {
    if(s == e) {
        tree[n] = arr[s];
        return;
    }

    int m = (s + e) / 2;
    init_tree(2 * n, s, m);
    init_tree(2 * n  + 1, m + 1, e);

    tree[n] = min(tree[2 * n], tree[2 * n + 1]);
}

void print_tree() {
    for(int i = 1; i <= 2 * n; i++) cout << tree[i] << " ";
    cout << '\n';
}

int query(int qs, int qe, int n, int s, int e) {
    if(qe < s || e < qs) return INF;
    if(qs <= s && e <= qe) return tree[n];

    int m = (s + e) / 2;
    int lval = query(qs, qe, 2 * n, s, m);
    int rval = query(qs, qe, 2 * n + 1, m + 1, e);

    return min(lval, rval);
}

void update(int idx, int target, int n, int s, int e) {
    if(idx < s || e < idx) return;
    if(s == e) {
        tree[n] = target;
        return;
    }

    int m = (s + e) / 2;
    update(idx, target, 2 * n, s, m);
    update(idx, target, 2 * n + 1, m + 1, e);

    tree[n] = min(tree[2 * n], tree[2 * n + 1]);
}

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init_tree(1, 1, n);

    cin >> m;
    
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if(a == 1) update(b, c, 1, 1, n);
        else if(a == 2) {
            if(b < c) cout << query(b, c, 1, 1, n) << '\n';
            else cout << query(c, b, 1, 1, n) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    return 0;
}
