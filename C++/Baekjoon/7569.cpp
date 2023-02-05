#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 101

int M, N, H;
int box[MAX][MAX][MAX];
int state[MAX][MAX][MAX] = {0,};
int distance_box[MAX][MAX][MAX] = {0,};
int axis_x[6] = {1,0,0,-1,0,0};
int axis_y[6] = {0,1,0,0,-1,0};
int axis_z[6] = {0,0,1,0,0,-1};
queue<tuple<int, int, int>> q;

int m = 0;

void bfs(){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        state[x][y][z] = true;
        q.pop();

        for(int i = 0; i < 6; i++){
            
            int bfs_x = x + axis_x[i];
            int bfs_y = y + axis_y[i];
            int bfs_z = z + axis_z[i];
            
            if(bfs_x < 0 || bfs_x >= N || bfs_y < 0 || bfs_y >= M || bfs_z < 0 || bfs_z >= H){
                continue; //범위 안에 없으면 스킵
            }

            if(box[bfs_x][bfs_y][bfs_z] == 0 && state[bfs_x][bfs_y][bfs_z] == false){
                box[bfs_x][bfs_y][bfs_z] = 1;
                q.push(make_tuple(bfs_x, bfs_y, bfs_z));
                state[bfs_x][bfs_y][bfs_z] = true;
                distance_box[bfs_x][bfs_y][bfs_z] = distance_box[x][y][z] + 1;
            }
        }
    }
}

int main(){
    cin >> M >> N >> H;
    int a = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < H; k++){
                int str;
                cin >>  str;
                box[i][j][k] = str;
                if(box[i][j][k] == 1){
                    q.push(make_tuple(i, j, k));
                    state[i][j][k] = true;
                }
                if(box[i][j][k] == 0){
                    a = 1;
                }
            }
            
        }
    }
    if(a == 0){
        cout << 0;
        return 0;
    }

    bfs();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < H; k++){
                if(box[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
                if(m < distance_box[i][j][k]){
                    m = distance_box[i][j][k];
                }
            }
        }
    }
    
    if(m == 0){
        cout << m;
    }
    else{
        cout << m - 2;
    }

    return 0;
}