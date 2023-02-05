#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001

int M, N;
int box[MAX][MAX];
int state[MAX][MAX] = {0,};
int distance_box[MAX][MAX] = {0,};
int axis_x[4] = {0,0,-1,1};
int axis_y[4] = {1,-1,0,0};
queue<pair<int, int>> que;

int m = 0;

void bfs(){
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++){
            int bfs_x = x + axis_x[i];
            int bfs_y = y + axis_y[i];

            if(bfs_x < 0 || bfs_x >= N || bfs_y < 0 || bfs_y >= M){
                continue; //범위 안에 없으면 스킵
            }

            if(box[bfs_x][bfs_y] == 0 && state[bfs_x][bfs_y] == false){
                box[bfs_x][bfs_y] = 1;
                que.push(make_pair(bfs_x, bfs_y));
                state[bfs_x][bfs_y] = true;
                distance_box[bfs_x][bfs_y] = distance_box[x][y] + 1;
            }
        }
    }
}

int main(){
    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int str;
            cin >>  str;
            box[i][j] = str;
            if(box[i][j] == 1){
                que.push(make_pair(i, j));
                state[i][j] = true;
            }
        }
    }

    bfs();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(box[i][j] == 0){
                cout << "-1";
                return 0;
            }
            if(m < distance_box[i][j]){
                m = distance_box[i][j];
            }

        }
    }

    cout << m;
    return 0;
}