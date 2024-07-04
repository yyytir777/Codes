#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int lamp[MAX][MAX];
int n, m, k;
map<string, int> pattern;

bool validate(pair<string, int> p) {
    int cnt = 0;
    for(char letter : p.first) {
        if(letter == '0') cnt++;
    }

    if(cnt - k > 0) return false;
    else if((k - cnt) % 2 == 0) return true;
    else return false;
}

int main() {
    cin >> n >> m;

    string tmp;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;

        if(pattern.find(tmp) == pattern.end()) pattern[tmp] = 1;
        else pattern[tmp]++;

    }

    cin >> k;
    int max_num = 0;
    for(auto element : pattern) {
        if(validate(element)) max_num = max(max_num, element.second);
    }

    cout << max_num;
}