#include <iostream>
#include <stack>
#define n 100
using namespace std;

int adj_matrix[n][n] = {0,};
bool visitied[n] = {0,};
stack<int> s;

void DFS(int v){
    visitied[v] = true;
    s.push(v);

    while(!s.empty()){
        v = s.top();
        s.pop();
        cout << v << ' ';

        for(int i = n; i >= 1; i--){
            if(adj_matrix[v][i] == 1 && visitied[i] == false){ //정점과 연결되어있고 방문X
                visitied[i] = true;
                s.push(i);
            }
        }
    }
}


int main() {
	adj_matrix[1][2] = 1;
    adj_matrix[1][3] = 1;
    adj_matrix[1][4] = 1;
    adj_matrix[2][5] = 1;
    adj_matrix[2][6] = 1;
    adj_matrix[2][7] = 1;
    adj_matrix[2][11] = 1;
    adj_matrix[2][12] = 1;
    adj_matrix[3][8] = 1;
    adj_matrix[3][9] = 1;
    adj_matrix[3][10] = 1;

	DFS(1);
}