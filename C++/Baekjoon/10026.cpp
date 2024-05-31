#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, cnt1, cnt2;
char graph1[MAX][MAX];
char graph2[MAX][MAX];

bool visited1[MAX][MAX] = {0,};
bool visited2[MAX][MAX] = {0,};
queue<pair<int, int>> q;

int row_axis[4] = {1, -1, 0, 0};
int col_axis[4] = {0, 0, -1, 1};

void bfs1(int i, int j) {
    visited1[i][j] = 1;
    q.push({i, j});

    while(!q.empty()) {
        pair<int, int> point = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int row = point.first + row_axis[i];
            int col = point.second + col_axis[i];

            if (row < 0 || row >= MAX || col < 0 || col >= MAX) continue;
            if (graph1[point.first][point.second] == graph1[row][col] && visited1[row][col] == false) {
                q.push({row, col});
                visited1[row][col] = 1;
            }
        }
    }
}

void bfs2(int i, int j) {
    visited2[i][j] = 1;
    q.push({i, j});

    while(!q.empty()) {
        pair<int, int> point = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int row = point.first + row_axis[i];
            int col = point.second + col_axis[i];

            if (row < 0 || row >= MAX || col < 0 || col >= MAX) continue;
            if (graph2[point.first][point.second] == graph2[row][col] && visited2[row][col] == false) {
                q.push({row, col});
                visited2[row][col] = 1;
            }
        }
    }
}

int user1() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited1[i][j] == false) {
                bfs1(i, j);
                cnt1++;
            }
        }
    }
    return cnt1;
}

int user2() {
        for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited2[i][j] == false) {
                bfs2(i, j);
                cnt2++;
            }
        }
    }
    return cnt2;
}

int main() {
    cin >> n;

    string tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        
        for(int j = 0; j < tmp.length(); j++) {
            graph1[i][j] = tmp[j];
            graph2[i][j] = tmp[j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph2[i][j] == 'G') graph2[i][j] = 'R';
        }
    }

    cout << user1() << " " << user2();
}