#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 9
using namespace std;

queue<pair<int, int>> q;

int idx_x[4] = {0,0,1,-1};
int idx_y[4] = {1,-1,0,0};
int original[MAX][MAX];
int arr[MAX][MAX];

void bfs(){

}

int main(){
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> original[i][j];
        }
    }

    
    return 0;
}