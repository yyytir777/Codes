#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n;
int graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};
queue<pair<int, int>> q;
vector<int> max_vector;

int row_axis[4] = {0, 0, -1, 1};
int col_axis[4] = {1, -1, 0, 0};

void init_queue() {
    while(!q.empty()) q.pop();
}

void init_visited() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

}

void bfs(pair<int, int> pos, int height) {
    init_queue();

    q.push(pos);
    visited[pos.first][pos.second] = 1;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_row = cur_pos.first + row_axis[i];
            int next_col = cur_pos.second + col_axis[i];
            pair<int, int> next_pos = {next_row, next_col};

            if(next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;

            if(visited[next_row][next_col] == 0 && graph[next_row][next_col] > height) {
                q.push(next_pos);
                visited[next_row][next_col] = 1;
            }
        }
    }
}

int main() {
    cin >> n;

    int tmp, max_height = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> tmp;
            graph[i][j] = tmp;
            max_height = max(max_height, tmp);
        }
    }
    
    for(int h = max_height; h >= 0; h--) {
        int cnt = 0;
        init_visited();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] > h && visited[i][j] == 0) {
                    bfs({i,j}, h);
                    cnt++;
                }
            }
        }
        max_vector.push_back(cnt);
    }

    sort(max_vector.begin(), max_vector.end());

    cout << max_vector[max_vector.size() - 1];
}