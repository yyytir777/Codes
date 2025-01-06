// 1976 cpp
#include <bits/stdc++.h>
#define MAX 201
using namespace std;

int n, m;
int parent[MAX];
vector<int> travel;

void init_parent() {
    for(int i = 1; i <= n; i++) parent[i] = i;
}

int getParent(int num) {
    if(parent[num] == num) return num;

    return getParent(parent[num]);
}

void merge(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if(a == b) return;
    parent[a] = b;
}

void input() {
    cin >> n >> m;
    init_parent();

    bool flag;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> flag;
            if(flag) {
                merge(i, j);
            }
        }
    }

    int num;
    for(int i = 0; i < m; i++) {
        cin >> num;
        travel.push_back(num);
    }
}

void print_parent() {
    for(int i = 1; i <= n; i++) {
        cout << parent[i] << " ";
    }
    cout << '\n';
}

void solve() {
    int node1 = travel[0];
    for(int i = 1; i < m; i++) {
        int node2 = travel[i];
        if(getParent(node1) != getParent(node2)) {
            cout << "NO";
            return;
        }
        node1 = node2;
    }
    cout << "YES";
}

int main() {
    input();
    solve();
}