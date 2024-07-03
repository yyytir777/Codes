#include <bits/stdc++.h>
#define MAX 100001
#define INF 1000001234
using namespace std;

int arr[MAX];
int tree[4 * MAX];
int n, m;

int init(int node, int start, int end) {
    if(start == end) {
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    int lval = init(node * 2, start, mid);
    int rval = init(node * 2 + 1, mid + 1, end);

    int min_value = min(lval, rval);
    tree[node] = min_value;
    return tree[node];
}

int query(int left, int right, int node, int start, int end) {
    if(end < left || right < start) return INF;
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    int lval = query(left, right, node * 2, start, mid);
    int rval = query(left, right, node * 2 + 1, mid + 1, end);

    return min(lval, rval);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        printf("%d\n", query(a, b, 1, 1, n));
    }
}