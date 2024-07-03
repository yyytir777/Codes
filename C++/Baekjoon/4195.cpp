#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

int parent[MAX];
int friends[MAX];

void init(int n) {
    for(int i = 0; i < MAX; i++) {
        parent[i] = i;
        friends[i] = 1;
    }
}

int getParent(int n) {
    if (parent[n] == n) return n;
    return parent[n] = getParent(parent[n]);
}

void union_find(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a > b) {
        parent[b] = a;
        friends[a] += friends[b];
    }
    else if (a < b) {
        parent[a] = b;
        friends[b] += friends[a];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;

    int f;
    int tmp1_idx, tmp2_idx;
    while(tc--) {
        map<string, int> m;
        cin >> f;

        init(f);

        string tmp1, tmp2;
        int idx = 1;
        for(int i = 0; i < f; i++) {
            cin >> tmp1 >> tmp2;
            
            if(m.find(tmp1) == m.end()) { // 없다면,
                m[tmp1] = idx;
                tmp1_idx = idx;
                idx++;
            }
            else tmp1_idx = m.find(tmp1)->second;

            if(m.find(tmp2) == m.end()) {
                m[tmp2] = idx;
                tmp2_idx = idx;
                idx++;
            }
            else tmp2_idx = m.find(tmp2)->second;

            union_find(tmp1_idx, tmp2_idx);
            printf("%d\n", friends[getParent(tmp2_idx)]);
        }
    }
}