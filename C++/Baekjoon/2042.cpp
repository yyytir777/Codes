#include <iostream>
using namespace std;

#define MAX 1000001

long long arr[MAX];
long long tree[MAX * 4];

void init(long long start, long long end, long long node) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    long long mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// i : index, x : 변경할 값, n : 변경할 위치, s : start, e : end
long long update(long long i, long long x, long long node, long long start, long long end) {
    if (i < start || end < i) return tree[node];
    if (i <= start && end <= i) return tree[node] = x;

    long long mid = (start + end) / 2;
    long long lval = update(i, x, node * 2, start, mid);
    long long rval = update(i, x, node * 2 + 1, mid + 1, end);

    return tree[node] = lval + rval;
}

long long query(long long left, long long right, long long node, long long start, long long end) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    long long mid = (start + end) / 2;
    long long lval = query(left, right, node * 2, start, mid);
    long long rval = query(left, right, node * 2 + 1, mid + 1, end);
    
    return lval + rval;
}

int main(){
    
    long long N, M, K;
    cin >> N >> M >> K;

    for (long long i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, N, 1);

    long long a, b, c;
    for (long long i = 0; i < M + K; i++) {
        cin >> a >> b >> c;

        // b번째 수를 c로 변경
        if (a == 1) {
            update(b, c, 1, 1, N);
        }

        // b번째 수부터 c번째 수까지의 합
        else if (a == 2) {
            cout << query(b, c, 1, 1, N) << '\n';
        }
    }
    return 0;
}