#include <bits/stdc++.h>
#define MAX 301
using namespace std;

int n, m;
int arr[MAX][MAX] = {0,};
int melting_arr[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};

int row_axis[4] = {0, 0, -1, 1};
int col_axis[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;

void iceMelted() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int melted_cnt = 0;
            for(int k = 0; k < 4; k++) {
                if(arr[i][j] == 0) continue;

                int row = i + row_axis[k];
                int col = j + col_axis[k];

                if(arr[row][col] == 0) melted_cnt++;
            }
            melting_arr[i][j] = melted_cnt;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] -= melting_arr[i][j];
            if(arr[i][j] < 0) arr[i][j] = 0;
        }
    }
}

void bfs(pair<int, int> start) {
    if(arr[start.first][start.second] == 0) return;

    q.push(start);
    visited[start.first][start.second] = 1;

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nxt_row = row + row_axis[i];
            int nxt_col = col + col_axis[i];

            if(arr[nxt_row][nxt_col] != 0 && visited[nxt_row][nxt_col] == 0) {
                q.push({nxt_row, nxt_col});
                visited[nxt_row][nxt_col] = 1;
            }
        }
    }
}

bool isDetached() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == 0 && arr[i][j] != 0) {
                bfs({i, j});
                cnt++;
            }
        }
    }
    if(cnt >= 2) return true;
    else return false;
}

bool isAllMelted() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] != 0) return false;
        }
    }
    return true;
}

void input() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\n";
}

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
}

void solve() {
    int time = 0;
    while(true) {
        iceMelted();
        time++;
        init();

        if (isDetached()) { //분리되었으면
            cout << time;
            return;
        }

        if(isAllMelted()) break;
    }
    cout << "0";
}

int main() {
    input();
    solve();
}