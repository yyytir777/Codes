#include <iostream>
#define MAX 128
#define WHITE 0
#define BLUE 1
using namespace std;
int white = 0;
int blue = 0;

int N;

int arr[MAX][MAX];

void divide(int row_start, int row_end, int col_start, int col_end) {
    int w_cnt = 0;
    int b_cnt = 0;

    for(int i = row_start; i <= row_end; i++) {
        for(int j = col_start; j <= col_end; j++) {
            if(arr[i][j] == WHITE) w_cnt++;
            else if(arr[i][j] == BLUE) b_cnt++;
        }
    }

    int sum_cnt = (row_end - row_start + 1) * (row_end - row_start + 1);
    int row_mid = (row_start + row_end) / 2;
    int col_mid = (col_start + col_end) / 2;

    // 전부 흰색일 때
    if(w_cnt == sum_cnt) white++;
    // 전부 파란색일 때
    else if(b_cnt == sum_cnt) blue++;
    // 나눠야 할 때
    else {
        divide(row_start, row_mid, col_start, col_mid);
        divide(row_start, row_mid, col_mid + 1, col_end);
        divide(row_mid + 1, row_end, col_start, col_mid);
        divide(row_mid + 1, row_end, col_mid + 1, col_end);
    }
}


int main() {
    cin >> N;
    for(int i =0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    divide(0, N - 1, 0, N - 1);

    cout << white << endl << blue;
}