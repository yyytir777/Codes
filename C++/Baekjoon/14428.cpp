// 14428 cpp
#include <bits/stdc++.h>
#define MAX 100001
#define INF LLONG_MAX
#define ll long long
using namespace std;

typedef pair<ll, int> Pair;

int n, m;
int arr[MAX] = {0,};
Pair tree[MAX * 4];

Pair minPair(Pair &a, Pair &b) {
    if(a.first < b.first) return a;
    if(a.first > b.first) return b;
    return (a.second < b.second) ? a : b;    
}

// 쿼리 값 -> [a,b]에서 가장 작은 값의 인덱스
void init(int n, int s, int e) {
    if(s == e) {
        tree[n] = {arr[s], s};
        return;
    }

    int mid = (s + e) / 2;
    init(2 * n, s, mid);
    init(2 * n + 1, mid + 1, e);
    tree[n] = minPair(tree[2*n], tree[2*n+1]);
}

Pair query(int qs, int qe, int n, int s, int e) {
    if(e < qs || qe < s) return {INF, INF};
    if(qs <= s && e <= qe) return tree[n];

    int mid = (s + e) / 2;
    Pair result1 = query(qs, qe, 2 * n, s, mid);
    Pair result2 = query(qs, qe, 2 * n + 1, mid + 1, e);

    return minPair(result1, result2);
}

void update(int idx, int target, int n, int s, int e) {
    if(idx < s || e < idx) return;
    if(s == e) {
        tree[n] = {target, idx};
        return;
    }

    int mid = (s + e) / 2;
    update(idx, target, 2 * n, s, mid);
    update(idx, target, 2 * n + 1, mid + 1, e);
    
    tree[n] = minPair(tree[2*n], tree[2*n+1]);
}

void input() {
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    init(1, 1, n);

    cin >> m;
    
    int a, b, c;    
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if(a == 1) {
            update(b, c, 1, 1, n);
        }
        else if(a == 2) {
            cout << query(b, c, 1, 1, n).second << '\n';
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