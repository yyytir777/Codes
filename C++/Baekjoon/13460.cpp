// 13460 cpp
#include <bits/stdc++.h>
#define BLANK '.'
#define WALL '#'
#define HOLE 'O'
#define RED 'R'
#define BLUE 'B'
#define MAX 10
using namespace std;

struct node {
    int x;
    int y;
    int cnt;
    int dist;
};

int n, m;
char graph[MAX][MAX];
queue<node> red;
queue<node> blue;

int row_axis[4] = {1, -1, 0, 0};
int col_axis[4] = {0, 0, 1, -1};

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == RED) {
                node init_red = {i, j, 0, 0};
                red.push(init_red);
            }
            else if(graph[i][j] == BLUE) {
                node init_blue = {i, j, 0, 0};
                blue.push(init_blue);
            }
        }
    }
}

char getGraph(int r, int c) {
    return graph[r][c];
}

node forward(node s, int direction) {
    int row = s.x;
    int col = s.y;
    while(true) {
        s.dist++;
        row += row_axis[direction];
        col += col_axis[direction];

        //구멍에 들어갔다면
        if(getGraph(row, col) == HOLE) {
            s.x = row;
            s.y = col;
            return s;
        }

        // 벽에 도달했을 시
        if(getGraph(row, col) == WALL || row < 0 || row > n || col < 0 || col > m) {
            s.x = row - row_axis[direction];
            s.y = col - col_axis[direction];
            return s;
        }
    }
}

int bfs() {
    while(red.front().cnt < 10 || blue.front().cnt < 10) {
        node cur_red = red.front();
        node cur_blue = blue.front();
        cur_red.dist = 0; red.pop();
        cur_blue.dist = 0; blue.pop();

        for(int i = 0; i < 4; i++) {
            node nxt_red = forward(cur_red, i);
            node nxt_blue = forward(cur_blue, i);

            nxt_red.cnt += 1;
            nxt_blue.cnt += 1;

            if(getGraph(nxt_blue.x, nxt_blue.y) == HOLE) continue;

            if(getGraph(nxt_red.x, nxt_red.y) == HOLE) return nxt_red.cnt;

            if(nxt_red.x == nxt_blue.x && nxt_red.y == nxt_blue.y) {
                if(nxt_red.dist > nxt_blue.dist) {
                    nxt_red.x -= row_axis[i];
                    nxt_red.y -= col_axis[i];
                }
                else {
                    nxt_blue.x -= row_axis[i];
                    nxt_blue.y -= col_axis[i];
                }
            }

            red.push(nxt_red);
            blue.push(nxt_blue);
        }
    }
    return -1;
}

void solve() {
    int ans = bfs();
    cout << ans;
}

void print_graph() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout <<  graph[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    input();
    solve();
    return 0;
}