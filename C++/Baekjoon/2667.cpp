#include <iostream>
#include <algorithm>
#include<vector>
#define n 26
using namespace std;

int N;
int map[n][n];
int state[n][n] = {0,};
int complex_cnt = 0; //단지 개수
int cnt; //단지 내 집 개수
int axis_x[4] = {0,0,-1,1};
int axis_y[4] = {1,-1,0,0};
vector<int> house;

void DFS(int x, int y){
    cnt++;
    int dfs_x;
    int dfs_y;
    state[x][y] = true;

    for(int i = 0; i < 4; i++){ //상하좌우 인접한 노드를 찾게 해줌
        dfs_x = x + axis_x[i];
        dfs_y = y + axis_y[i];

        if(dfs_x < 0 || dfs_x >= N || dfs_y < 0 || dfs_y >= N){ //맵을 벗어났을때
            continue;
        }

        if(map[dfs_x][dfs_y] == 1 && state[dfs_x][dfs_y] == 0){ // 인접한 집이 존재함과 동시에 탐색되지 않은 집일때
            DFS(dfs_x, dfs_y);
        }
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < N; j++){
            map[i][j] = input[j] - 48;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1 && state[i][j] == 0){
                cnt = 0; //단지 안에 하나는 보장
                DFS(i, j);
                complex_cnt += 1;
                house.push_back(cnt); //vector에 단지 내 집 개수 push & 원소의 개수는 곧 단지의 개수
            }
        }
    }

    sort(house.begin(), house.end());
    cout << complex_cnt << '\n';
    vector<int>::iterator iter;

    for(iter = house.begin(); iter < house.end(); iter++){
        cout << *iter << '\n';
    }

    return 0;
}