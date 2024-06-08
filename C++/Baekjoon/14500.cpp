#include <bits/stdc++.h>
#define MAX 510
using namespace std;

int n, m;
int w[MAX][MAX];
bool visited[MAX][MAX] = {0,};
int row_axis[4] = {1, -1, 0, 0};
int col_axis[4] = {0, 0, -1, 1};
int answer;

void shape1(int x, int y) { // ㅜ 모양
    int sum = 0;
    sum = w[x][y] + w[x][y + 1] + w[x][y + 2] + w[x + 1][y + 1];
    answer = max(answer, sum);
}

void shape2(int x, int y) { // ㅏ 모양
    int sum = 0;
    sum = w[x][y] + w[x + 1][y] + w[x + 2][y] + w[x + 1][y + 1];
    answer = max(answer, sum);
}

void shape3(int x, int y) { // ㅗ 모양
    int sum = 0;
    sum = w[x][y] + w[x][y + 1] + w[x][y + 2] + w[x - 1][y + 1];
    answer = max(answer, sum);
}

void shape4(int x, int y) { // ㅓ 모양
    int sum = 0;
    sum = w[x][y] + w[x][y + 1] + w[x - 1][y + 1] + w[x + 1][y + 1];
    answer = max(answer, sum);
}


// depth가 4이면 완료
void dfs(int x, int y, int depth, int sum) {
    if(depth == 3) {
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < 4; i++) {
        int row = x + row_axis[i];
        int col = y + col_axis[i];

        if(row < 0 || row >= n || col < 0 || col >= m) continue;
        if(visited[row][col]) continue;

        visited[row][col] = 1;
        dfs(row, col, depth + 1, sum + w[row][col]);
        visited[row][col]= 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> w[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = 1;
            dfs(i, j, 0, w[i][j]);
            visited[i][j] = 0;

            if(j + 2 < m && i + 1 < n) shape1(i, j); // ㅜ 모양
            if(i + 2 < n && j + 1 < m) shape2(i, j); // ㅏ 모양
            if(i - 1 >= 0 && j + 2 < m) shape3(i, j); // ㅗ 모양
            if(i + 1 < n && i - 1 >= 0 && j + 1 < m) shape4(i, j); // ㅓ 모양
        }
    }
    cout << answer;
}