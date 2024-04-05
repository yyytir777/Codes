#include <iostream>
#include <queue>
#define MAX 100005
using namespace std;

bool state[MAX] = {0,};
int time[MAX] = {0,};
queue<int> q;

void bfs(int n, int k) {
    q.push(n);
    state[n] = true;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        if(v == k) {
            break;
        }
        if(state[2 * v] == false && 2 * v < MAX && 2 * v >= 0) {
            q.push(2 * v);
            state[2 * v] = true;
            time[2 * v] = time[v] + 1;
        }
        if(state[v + 1] == false && v + 1 < MAX && v + 1 >= 0) {
            q.push(v + 1);
            state[v + 1] = true;
            time[v + 1] = time[v] + 1;
        }
        if(state[v - 1] == false && v - 1 < MAX && v - 1 >= 0) {
            q.push(v - 1);
            state[v - 1] = true;
            time[v - 1] = time[v] + 1;
        }
    }
    cout << time[k] << '\n';
}


int main() {
    int n, k;
    cin >> n >> k;

    bfs(n, k);
}