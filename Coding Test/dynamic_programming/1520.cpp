#include <iostream>
#define MAX 505
using namespace std;

int M, N;

int arr[MAX][MAX] = {0,};
int x_axis[4] = {1,-1,0,0};
int y_axis[4] = {0,0,-1,1};

int dp[MAX][MAX] = {-1,};
int cnt = 0;

int dfs(int y, int x) {

    if(y == M && x == N) return 1;

    if(dp[y][x] == -1) {
        dp[y][x] = 0;

        for(int i = 0; i < 4; i++) {
            int nx = x + x_axis[i];
            int ny = y + y_axis[i];

            if(arr[ny][nx] != 0 && arr[ny][nx] < arr[y][x]) {
                dp[y][x] += dfs(ny, nx);
            }
        }
    }

    return dp[y][x];
}

int main() {
    cin >> M >> N;

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    

    cout << dfs(1,1) << endl;
}