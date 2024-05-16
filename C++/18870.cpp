#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

map<int, int> m;
set<int> s;
vector<int> v;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        s.insert(tmp);
        v.push_back(tmp);
    }

    int i = 0;
    for(auto tmp : s) m.insert({tmp, i++});

    for(auto tmp : v) cout << m.find(tmp)->second << " ";
}