#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define M 101
#define check -1

int paper[M][M] = {0,};
int m, n, k;
int area = 0;
int axis_x[4] = {0,0,-1,1};
int axis_y[4] = {1,-1,0,0};
vector<int> v;

void dfs(int x, int y){
    int dfs_x;
    int dfs_y;
    paper[x][y] = check;

    for(int i = 0; i < 4; i++){ //상하좌우 인접한 노드를 찾게 해줌
        dfs_x = x + axis_x[i];
        dfs_y = y + axis_y[i];

        if(dfs_x < 0 || dfs_x >= n || dfs_y < 0 || dfs_y >= m){ //맵을 벗어났을때
            continue;
        }

        if(paper[dfs_x][dfs_y] == 0){ // 인접한 집이 존재함과 동시에 탐색되지 않은 집일때
            area++;
            dfs(dfs_x, dfs_y);
        }
    }
}

int main(){
    cin >> m >> n >> k; //m -> y값 & n -> x값
    int x1, x2, y1, y2;
    for(int i = 0; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j < x2; j++){
            for(int k = y1; k < y2; k++){
                paper[j][k] += 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(paper[i][j] == 0){
                area = 1;
                dfs(i, j);
                v.push_back(area);
            }
        }
    }

    cout << v.size() << '\n';

    sort(v.begin(), v.end());

    vector<int>::iterator iter;

    for(iter = v.begin(); iter < v.end(); iter++){
        cout << *iter << " ";
    }
    return 0;
}