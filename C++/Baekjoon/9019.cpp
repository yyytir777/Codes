#include <bits/stdc++.h>
#define MAX 10010
using namespace std;

char instruction[4] = {'D', 'S', 'L', 'R'};
bool visited[MAX] = {0,};

int instructionD(int n) {
    return (2 * n) % 10000;
}

int instructionS(int n) {
    return (n - 1) < 0 ? 9999 : (n - 1);
}

int instructionL(int n) {
    int result = (n % 1000) * 10 + (n / 1000);
    return result;
}

int instructionR(int n) {
    int result = (n % 10) * 1000 + (n / 10);
    return result;
}

void bfs(int start, int end) {
    queue<pair<int, string>> q;
    q.push({start, ""});
    visited[start] = 1;

    while(!q.empty()) {
        int v = q.front().first;
        string inst = q.front().second;
        q.pop();

        if(v == end) {
            cout << inst << '\n';
            return;
        }

        int d = instructionD(v);
        if(!visited[d]) {
            visited[d] = 1;
            q.push({d, inst + 'D'});
        }

        int s = instructionS(v);
        if(!visited[s]) {
            visited[s] = 1;
            q.push({s, inst + 'S'});
        }

        int l = instructionL(v);
        if(!visited[l]) {
            visited[l] = 1;
            q.push({l, inst + 'L'});
        }

        int r = instructionR(v);
        if(!visited[r]) {
            visited[r] = 1;
            q.push({r, inst + 'R'});
        }


    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;

        memset(visited, 0, sizeof(visited));

        bfs(a, b);
    }
    return 0;
}