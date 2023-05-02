#include <iostream>
#include <cstring>
using namespace std;

#define MAX 16
#define INF 987654321

int w[MAX][MAX];
int d[MAX][1 << MAX];
int N;


int TSP(int current, int visited){
    if(visited == (1 << N) - 1){
        if(w[current][0] == 0)
            return INF;
        else 
            return w[current][0];
    }

    if(d[current][visited] != -1)
        return d[current][visited];
    d[current][visited] = INF;

    for(int i = 0; i < N; i++){
        if(w[current][i] == 0) continue;
        if((visited & (1 << i)) == (1 << i)) continue;
        d[current][visited] = min(d[current][visited], w[current][i] + TSP(i, visited | 1 << i));
    }
    return d[current][visited];
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> w[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << TSP(0, 1);
    return 0;
}