#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

string mbti[MAX];
vector<int> v;
int answer;

int diff(string a, string b) {
    int cnt = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

void calc() {
    int sum = 0;
    sum = diff(mbti[v[0]], mbti[v[1]]) + diff(mbti[v[0]], mbti[v[2]]) + diff(mbti[v[2]], mbti[v[1]]);
    answer = min(answer, sum);
}

void pick(int n) {
    if(v.size() == 3) {
        calc();
        return;
    }

    int idx = v.empty() ? 0 : v.back() + 1;

    for(int nxt = idx; nxt < n; nxt++) {
        v.push_back(nxt);
        pick(n);
        v.pop_back();
    }
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> mbti[i]; 
    }

    if(n > 32) {
        cout << "0" << '\n';
        return;
    }

    pick(n);

    cout << answer << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        answer = 1000000;
        solve();
    }
}