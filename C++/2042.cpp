#include <iostream>
#define MAX 1000001
using namespace std;

int N, M, K;
int arr[MAX] = {0,};
int tree[4 * MAX];

int init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;

    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

int sum(int start, int end, int node, int left, int right) {
    //겹치지 않으므로 탐색 X
    if(left > end || right < start) return 0;

    // [start, end]가 [left, right]에 포함
    if(left <= start && end <= right) return arr[node];

    // 
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int index, int node, int value) {
    if(index < start || index > end) return;

    tree[index] += value;
    if(start == end) return;

    if(start != end) {
        int mid = (start + end) / 2;
        update(start, mid, index, node, value);
        update(mid+1, end, index, node, value);
    }
}

int main(){
    cin >> N >> M >> K;

    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        arr[i+1] = tmp;
    }

    init(1, 0, N - 1);

    for(int i = 0; i < M + K; i++) {
        cin >> tmp;
        int b, c;
        // b번째 수를 c로 변경
        if(tmp == 1) {
            cin >> b >> c;
            update(0, N - 1, b - 1, 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        // b번째 수부터 c번째 수까지의 합 출력
        else if(tmp == 2) {
            cin >> b >> c;
            cout << sum(0, N - 1, 1, b - 1, c - 1);
        }
    }
}