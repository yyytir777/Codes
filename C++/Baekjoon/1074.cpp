#include <iostream>
using namespace std;

long long N, r, c;
long long cnt = 0;

void visit(long long row_start, long long row_end, long long col_start, long long col_end) {
    long long row_mid = (row_start + row_end) / 2;
    long long col_mid = (col_start + col_end) / 2;

    if(row_start == row_end && col_start == col_end) {
        if(row_start == r && col_start == c) cout << cnt;
            cnt++;
        return;
    }
    else {
        long long weight = ((row_end - row_start + 1) / 2) * ((row_end - row_start + 1) / 2);
        if(r <= row_mid && c <= col_mid) visit(row_start, row_mid, col_start, col_mid);
        else cnt += weight;

        if(r <= row_mid && col_mid <= c) visit(row_start, row_mid, col_mid + 1, col_end);
        else cnt += weight;

        if(row_mid <= r && c <= col_mid) visit(row_mid + 1, row_end, col_start, col_mid);
        else cnt += weight;

        if(row_mid <= r && col_mid <= c) visit(row_mid + 1, row_end, col_mid + 1, col_end);
        else cnt += weight;
    }
}

int main() {
    cin >> N >> r >> c;

    long long length = 1;
    for(long long i = 0; i < N; i++) {
        length *= 2;
    }

    visit(0, length - 1, 0, length - 1);
}