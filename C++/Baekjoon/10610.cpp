#include <bits/stdc++.h>
using namespace std;

vector<int> v;
string n;

int main() {
    cin >> n;

    bool flag = 0;
    for(int i = 0; i < n.size(); i++){
        if (n[i] == '0') flag = 1;
        v.push_back(n[i] - 48);
    }

    if(flag == 0) {
        cout << "-1";
        return 0;
    }

    sort(v.begin(), v.end());

    int sum = 0;
    string result;
    for(auto num : v) {
        result += to_string(v.back());
        sum += v.back();
        v.pop_back();
    }

    if(sum % 3 != 0) {
        cout << "-1";
        return 0;
    }
    cout << result;
    return 0;
}