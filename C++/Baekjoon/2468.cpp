#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};
queue<pair<int, int>> q;

int row_axis = {0, 0, -1, 1};
int col_axis = {1, -1, 0, 0};

void init_queue() {
    while(!q.empty()) q.pop();
}

int bfs(pair<int, int> pos) {
    init_queue();
    q.push(pos);
    visited[pos.first][pos.second] = 1;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            
            pair<int, int> next_pos = {cur_pos.first + row_axis[i], cur_pos.second + col_axis[i]};
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }


}