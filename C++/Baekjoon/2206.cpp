#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 1001
using namespace std;
// maze를 순회하며 한번씩 벽을 하나씩 뚫어 bfs 실행
int N, M;
int maze[MAX][MAX];
int distance[MAX][MAX] = {0,}
bool state[MAX][MAX] = {false,}
bool wall_check[MAX][MAX] = {false,}

int axis_x[4] = {0,0,-1,1};
int axis_y[4] = {1,-1,0,0};

queue<pair<int, int>> q;
vector<int> v;

void bfs(){
    int bfs_x, bfs_y;
    q.push(make_pair(0,0));
    state[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            bfs_x = x + axis_x[i];
            bfs_y = y + axis_y[i];

            if(bfs_x < 0 || bfs_x >= M || bfs_y < 0 || bfs_y >= N){
                continue;
            }

            if(maze[bfs_x][bfs_y] == 0 && state[bfs_x][bfs_y] == 0){
                state[bfs_x][bfs_y] = 1;
                q.push(make_pair(bfs_x, bfs_y));
                distance[bfs_x][bfs_y] = distance[x][y] + 1;
                v.push_back(distance[bfs_x][bfs_y]);
            }
        }
    }
}

int main(){
    cin >> M >> N;

    for(int i = 0; i < M; i++){
        string input;
        cin >> input;   
        for(int j = 0; j < N; j++){
            maze[i][j] = input[j] - 48;
        }
    }

    bfs();


    return 0;
}