#include <iostream>
#define MAX 1001
using namespace std;

int N, M;
int maze[MAX][MAX];
int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < M; j++){
            maze[i][j] = input[j] - 48;
        }
    }

    return 0;
}