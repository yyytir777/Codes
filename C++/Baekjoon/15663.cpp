// 15663 cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<vector<int>> seq;
bool visited[10] = {0,};

void input() {
    cin >> n >> m;

    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
}

void permutation_dfs(vector<int> &tmp_arr, int idx, int cnt) {
    if(cnt == m) {
        seq.push_back(tmp_arr);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
        visited[i] = 1;
        tmp_arr.push_back(arr[i]);
        permutation_dfs(tmp_arr, i + 1, cnt + 1);
        tmp_arr.pop_back();
        visited[i] = 0;
        }    
    }
}

void print_seq() {
    for(vector<int> v_element : seq) {
        for(int element : v_element) {
            cout << element << " ";
        }
        cout << '\n';
    }
}

bool isEqual(vector<int> a, vector<int> b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

void print(vector<int> v) {
    for(auto element : v) cout << element << " ";
    cout << '\n';
}


void solve() {
    vector<int> tmp;

    sort(arr.begin(), arr.end());

    permutation_dfs(tmp, 0, 0);

    sort(seq.begin(), seq.end());

    for(int i = 0; i < seq.size(); i++) {
        if(i >= 1) {
            bool equal = isEqual(seq[i-1], seq[i]);
            if(equal) continue;
            else print(seq[i]);
        }
        else print(seq[0]);
    }
}

int main() {
    input();
    solve();
    return 0;
}