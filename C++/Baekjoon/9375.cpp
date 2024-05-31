#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

bool search(string str) {
    for(pair<string, int> tmp : m) {
        if(tmp.first == str) return true;
    }
    return false;
}

int solve() {
    int n;
    cin >> n;

    string cloth, cloth_type;
    while(n--) {
        cin >> cloth >> cloth_type;
        if(search(cloth_type)) m[cloth_type]++;
        else m[cloth_type] = 1;
    }

    int sum = 1;
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        sum *= (iter->second + 1);
    }
    sum--;
    return sum;
}

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        cout << solve() << '\n';
        m.clear();
    }
}