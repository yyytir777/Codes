#include <bits/stdc++.h>
using namespace std;

map<string, int> leader_board;

bool compare(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n; cin >> n;

    string tmp;
    while(n--) {
        cin >> tmp;

        // 해당 책 이름이 없을 때        
        if(leader_board.find(tmp) == leader_board.end()) leader_board[tmp] = 1;
        // 해당 책 이름이 있으면
        else leader_board[tmp]++;
    }

    vector<pair<string, int>> v(leader_board.begin(), leader_board.end());
    sort(v.begin(), v.end(), compare);

    cout << v[0].first;
}