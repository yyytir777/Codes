#include <bits/stdc++.h>
#define MAX 100001
#define INF_MAX 9876543210
#define INF_MIN -9876543210
using namespace std;

int n, m;
int arr[MAX];
//   min, max
pair<int, int> tree[4 * MAX];

pair<int, int> init(int node, int start, int end) {
    if(start == end) return tree[node] = {arr[start], arr[end]};

    int mid = (start + end) / 2;
    pair<int, int> lval = init(node * 2, start, mid);
    pair<int, int> rval = init(node * 2 + 1, mid + 1, end);

    tree[node].first = min(lval.first, rval.first);
    tree[node].second = max(lval.second, rval.second);
    return tree[node];
}

pair<int, int> query(int left, int right, int node, int start, int end) {
    if(end < left || right < start) return {INF_MAX, INF_MIN};
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    pair<int, int> lval = query(left, right, node * 2, start, mid);
    pair<int, int> rval = query(left, right, node * 2 + 1, mid + 1, end);
    
    return {min(lval.first, rval.first), max(lval.second, rval.second)};
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
        pair<int, int> tmp = query(a, b, 1, 1, n);
        printf("%d %d\n", tmp.first, tmp.second);
    }
}