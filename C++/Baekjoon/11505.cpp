#include <bits/stdc++.h>
#define MAX 1001000
#define REST 1000000007
using namespace std;

int arr[MAX];
long long tree[4 * MAX];

long long init(int n, int start, int end) {
    if(start == end) return tree[n] = arr[start];

    int mid = (start + end) / 2;
    long long lval = init(n * 2, start, mid);
    long long rval = init(n * 2 + 1, mid + 1, end);
    return tree[n] = (lval * rval) % REST;
}

long long update(int i, int v, int n, int start, int end) {
    if(end < i || i < start) return tree[n];
    if(i <= start && end <= i) return tree[n] = v;

    int mid = (start + end) / 2;
    long long lval = update(i, v, n * 2, start, mid);
    long long rval = update(i, v, n * 2 + 1, mid + 1, end);

    return tree[n] = (lval * rval) % REST;
}

long long query(int left, int right, int n, int start, int end) {
    if(end < left || right < start) return 1;
    if(left <= start && end <= right) return tree[n];

    int mid = (start + end) / 2;
    long long lval = query(left, right, n * 2, start, mid);
    long long rval = query(left, right, n * 2 + 1, mid + 1, end);
    return (lval * rval) % REST;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);

    int a, b, c;
    for(int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;

        if(a == 1) {
            update(b, c, 1, 1, n);
        }
        else if(a == 2) {
            int answer = query(b, c, 1, 1, n);
            printf("%d\n", answer);
        }
    }
}