#include <iostream>
#define MAX 32768
using namespace std;

int arr[MAX][MAX];
int N, r, c;
int cnt = 0;

void visit(int row_start, int row_end, int col_start, int col_end) {
    int row_mid = (row_start + row_end) / 2;
    int col_mid = (col_start + col_end) / 2;

    if(row_start == row_mid && col_start == col_mid) {
        arr[row_start][col_start] = cnt++;
        arr[row_start][col_end] = cnt++;
        arr[row_end][col_start] = cnt++;
        arr[row_end][col_end] = cnt++;
        return;
    }
    else {
        visit(row_start, row_mid, col_start, col_mid);
        visit(row_start, row_mid, col_mid + 1, col_end);
        visit(row_mid + 1, row_end, col_start, col_mid);
        visit(row_mid + 1, row_end, col_mid + 1, col_end);
    }
}


int main() {
    cin >> N >> r >> c;

    int length = 1;
    for(int i = 0; i < N; i++) {
        length *= 2;
    }

    visit(0, length - 1, 0, length - 1);

    cout << arr[r][c];
}