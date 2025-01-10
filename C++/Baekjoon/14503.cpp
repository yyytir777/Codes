// 14503 cpp
#include <bits/stdc++.h>
#define MAX 51
#define UNCLEAN 0
#define WALL 1
#define CLEAN 2
using namespace std;

typedef pair<int, int> Pair;

int n, m;
int r, c, d;
int arr[MAX][MAX];

// N, E, S, W
int row_axis[4] = {-1, 0, 1, 0};
int col_axis[4] = {0, 1, 0, -1};


int next(int direction) {
    if(direction == 0) return 3;
    else if(direction == 1) return 0;
    else if(direction == 2) return 1;
    else if(direction == 3) return 2;
}

int reverse(int direction) {
    if(direction == 0) return 2;
    else if(direction == 1) return 3;
    else if(direction == 2) return 0;
    else if(direction == 3) return 1;
}

void input() {
    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

bool nearIsUncleaned(Pair node) {
    for(int i = 0; i < 4; i++) {
        int near_row = node.first + row_axis[i];
        int near_col = node.second + col_axis[i];

        if(arr[near_row][near_col] == UNCLEAN) return true;
    }
    return false;
}

int bfs(Pair start) {
    queue<Pair> q;
    q.push(start);
    int cnt = 0;

    while(!q.empty()) {
        Pair cur = q.front();
        q.pop();

        // 청소되지 않은 경우
        if(arr[cur.first][cur.second] == UNCLEAN) {
            arr[cur.first][cur.second] = CLEAN;
            cnt++;
        }

        // 주변 중에 청소되지 않은 빈 칸이 있는 경우
        if(nearIsUncleaned(cur)) {
            int rep = 0;
            while(rep < 4) {
                rep++;
                d = next(d);
                int nxt_row = cur.first + row_axis[d];
                int nxt_col = cur.second + col_axis[d];

                if(arr[nxt_row][nxt_col] == UNCLEAN) {
                    q.push({nxt_row, nxt_col});
                    break;
                }
            }
        }
        else { // 주위가 청소된 경우 -> 후진
            int reverse_d = reverse(d);
            int nxt_row = cur.first + row_axis[reverse_d];
            int nxt_col = cur.second + col_axis[reverse_d];

            if(arr[nxt_row][nxt_col] != WALL) q.push({nxt_row, nxt_col});
        }
    }

    return cnt;
}

void solve() {
    int ans = bfs({r, c});
    cout << ans << '\n';
}

void print_arr() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    input();
    solve();
    return 0;
}