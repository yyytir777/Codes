#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<pair<long long, long long>> q;

long long bfs(long long a, long long b) {
    q.push({a, 1});

    while(!q.empty()) {
        long long v = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(v == b) return cnt;
        if(2 * v <= b) q.push({2 * v, cnt + 1});
        if(10 * v + 1 <= b) q.push({10 * v + 1, cnt + 1});
    }
    return -1;
}

int main(){
    long long A, B;
    cin >> A >> B;

    cout << bfs(A, B);
}