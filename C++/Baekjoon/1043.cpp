// 1043 cpp
#include <bits/stdc++.h>
#define MAX 51
using namespace std;

typedef pair<int, int> Pair;

int n, m;
vector<int> party[MAX];
vector<int> truth;
int parent[MAX];
int friends[MAX];

void init() {
    for(int i = 0; i < n; i++) parent[i] = i;
}

int getParent(int n) {
    if(parent[n] == n) return n;
    return parent[n] = getParent(parent[n]);
}

void mergeSet(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    parent[a] = b;
}

void input() {
    cin >> n >> m;

    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        int temp; cin >> temp;
        truth.push_back(temp);
    }

    for(int i = 0; i < m; i++) {
        int cnt; cin >> cnt;

        for(int j = 0; j < cnt; j++) {
            int temp; cin >> temp;
            party[i].push_back(temp);
        }
    }
}

void solve() {
    init();

    for(int i = 0; i < m; i++) {
        int set1 = party[i][0];
        for(int j = 1; j < party[i].size(); j++) {
            int set2 = party[i][j];
            mergeSet(set1, set2);
        }
    }

    int ans = m;
    for(int i = 0; i < m; i++) {

        bool flag = true;
        for(int j = 0; j < party[i].size(); j++) {

            if(!flag) break;
            for(int k = 0; k < truth.size(); k++) {
                if(getParent(truth[k]) == getParent(party[i][j])) {
                    flag = false;
                    break;
                }
            }
            if(!flag) ans--;
        }
    }
    cout << ans;
}

int main() {
    input();
    solve();
    return 0;
}