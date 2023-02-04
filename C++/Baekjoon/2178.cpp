#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
//최소 칸수이므로 BFS 사용

int N, M;
int maze[MAX][MAX];
int distance_maze[MAX][MAX] = {0,};
int state[MAX][MAX];

int axis_x[4] = {0,0,-1,1};
int axis_y[4] = {1,-1,0,0};

queue<pair<int, int>>q;

void BFS(int x, int y){
    q.push(make_pair(x,y));
    state[x][y] = true;
    distance_maze[x][y] += 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int bfs_x = x + axis_x[i];
            int bfs_y = y + axis_y[i];

            if(bfs_x < 0 || bfs_x >= N || bfs_y < 0 || bfs_y >= M){
                continue; //범위 안에 없으면 스킵
            }

            if(maze[bfs_x][bfs_y] == 1 && state[bfs_x][bfs_y] == false){
                q.push(make_pair(bfs_x, bfs_y));
                state[bfs_x][bfs_y] = true;
                distance_maze[bfs_x][bfs_y] = distance_maze[x][y] + 1;
            }
        }
    }
}

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < M; j++){
            maze[i][j] = input[j] - 48;
        }
    }
    BFS(0,0);

    cout << distance_maze[N-1][M-1];

    return 0;
}