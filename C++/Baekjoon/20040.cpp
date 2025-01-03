// 20040 cpp
#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

typedef pair<int, int> Pair;

int n, m;
vector<Pair> record;
int parent[MAX];

void initParent() {
    for(int i = 0; i < n; i++) parent[i] = i;
}

int getParent(int n) {
    if(parent[n] == n) return n;

    return getParent(parent[n]);
}

bool merge(Pair node) {
    int a = getParent(node.first);
    int b = getParent(node.second);

    if(a == b) return true;
    else {
        if(a > b) parent[a] = b;
        else parent[b] = a;
        return false;
    }
}

void print_parent() {
    for(int i = 0; i < n; i++) cout << parent[i] << " ";
    cout << endl;
}

void input() {
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        record.push_back({a,b});
    }
}

void solve() {
    initParent();

    int cnt = 1;
    vector<Pair> temp;
    for(Pair node : record) {
        bool isCycle = merge(node);
        if(isCycle) {
            cout << cnt;
            return;
        }
        else cnt++;
    }
    cout << "0";
}

int main() {
    input();
    solve();
    print_parent();
    return 0;
}