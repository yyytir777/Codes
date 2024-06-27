#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int parent[MAX];
int n, delete_node, root_node, cnt = 0;

int dfs(int start) {
    if(start == delete_node) return -1;

    bool flag = 0;
    for(int i = 0; i < n; i++) {
        if (parent[i] == start) {
            if(dfs(i) == 1) flag = 1;
        }
    }
    if(!flag) cnt++;
    return 1;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> parent[i];
        if(parent[i] == -1) root_node = i;
    }

    cin >> delete_node;

    dfs(root_node);

    cout << cnt;
}