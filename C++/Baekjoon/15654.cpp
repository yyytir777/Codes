#include <bits/stdc++.h>
#define MAX 10
using namespace std;

vector<int> v;
int arr[MAX];
bool visited[MAX] = {0,};
int n, m;

void dfs(int cnt) {
    if(cnt == m) {
        for(int tmp : v) {
            cout << tmp << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;

        v.push_back(arr[i]);
        visited[i] = 1;

        dfs(cnt + 1);

        v.pop_back();
        visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    for(int i = 0; i < n; i++) { 
        cin >> arr[i];
    }

    sort(arr, arr + n);

    dfs(0);
}