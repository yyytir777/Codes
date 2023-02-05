#include <iostream>
#include <queue>
using namespace std;

#define M 101
#define check 5
#define air 0
#define inner_cheeze 1
#define outer_cheeze 2
#define inner 3
/*
치즈 구멍 속을 inner(3)로 변환

판에 치즈 배치 후 공기(0)에서 맞닿아있는 치즈를 outer_cheeze(2)로 변환

공기에 닿으면 치즈가 녹음 -> outer_cheeze(1)가 녹음(0)

*/
/*
dfs(0,0)을 하면 바깥공기는 5, 치즈 안의 구멍은 0, 치즈는 1 이 됨
*/
int a, b;
int board[M][M];
int axis_x[4] = {0,0,-1,1};
int axis_y[4] = {1,-1,0,0};
int time = 0;
int c_cnt = 0;
queue<pair<int, int> q;

void bfs(){
    q.push(make_pair(0,0));
    board[0][0] = check;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << v << " ";
        //pop하면서 원소 출력

        for(int j = 1; j <= N; j++){
            if(adj_matrix[v][j] == 1 && state[j] == false){ //정점과 연결되어있고 방문X여야함
                q.push(j);
                state[j] = true;
            }
        }
    }
}

void dfs_check(){
    int x = 0;
    int y = 0;
    int dfs_x;
    int dfs_y;
    board[x][y] = check;

    for(int i = 0; i < 4; i++){ //상하좌우 인접한 노드를 찾게 해줌
        dfs_x = x + axis_x[i];
        dfs_y = y + axis_y[i];

        if(dfs_x < 0 || dfs_x >= b || dfs_y < 0 || dfs_y >= a){ //맵을 벗어났을때
            continue;
        }

        if(board[dfs_x][dfs_y] == 0){ // 인접한 집이 존재함과 동시에 탐색되지 않은 집일때
            dfs_check(dfs_x, dfs_y);
        }
    }
}

void dfs(){
    int x = 0;
    int y = 0;
    int dfs_x;
    int dfs_y;
    board[x][y] = check;

    for(int i = 0; i < 4; i++){ //상하좌우 인접한 노드를 찾게 해줌
        dfs_x = x + axis_x[i];
        dfs_y = y + axis_y[i];

        if(dfs_x < 0 || dfs_x >= b || dfs_y < 0 || dfs_y >= a){ //맵을 벗어났을때
            continue;
        }

        if(board[dfs_x][dfs_y] == 0){ // 인접한 집이 존재함과 동시에 탐색되지 않은 집일때
            dfs(dfs_x, dfs_y);
        }
    }
}

bool isNotCheeze(){
    int r = 0;
    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            if(board[i][j] == 1){
                r = 1;
            }
        }
    }
    if(r == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cin >> b >> a;

    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            int str;
            cin >>  str;
            board[i][j] = str;
        }
    }

    dfs_check(); //바깥공기를 5로 초기화

    while(1){
        int cnt = 0;
        if(isNotCheeze()){ //치즈가 없다면
            cout << time << '\n' << cnt;
            return 0;
        }
        else{
            dfs()
            cnt = c_cnt;
        }
    }




    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}