#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

queue<pair<int, int>> q;
int graph[MAX][MAX] = {0,};
bool state[MAX][MAX] = {false,};
int time[MAX][MAX];
int axis_x[4] = {1, -1, 0, 0};
int axis_y[4] = {0, 0, -1, 1};


void bfs(int n, int m) {
    q.push(make_pair(0,0));
    state[0][0] = true;
    time[0][0] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            if(graph[x + axis_x[i]][y + axis_y[i]] == 1 && state[x + axis_x[i]][y + axis_y[i]] == false) {
                q.push(make_pair(x + axis_x[i], y + axis_y[i]));
                state[x + axis_x[i]][y + axis_y[i]] = true;
                time[x + axis_x[i]][y + axis_y[i]] = time[x][y] + 1;

                if((x + axis_x[i]) == (n-1) && (y + axis_y[i]) == (m-1)) {
                    cout << time[x + axis_x[i]][y + axis_y[i]];
                    return;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++) {
            graph[i][j] = temp[j] - 48;
        }
    }
    bfs(n,m);
}