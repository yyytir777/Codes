#include <bits/stdc++.h>
#define MAX 10
using namespace std;
//  key : value = {숫자, 개수}
map<int, int> m_cnt;
vector<int> v;
bool visited[MAX] = {0,};
map<int, int>::iterator iter = m_cnt.begin();
int n, m;


void dfs(int depth) {
    if(depth == m) {
        for(int tmp : v) {
            cout << tmp << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < m_cnt.size(); i++) {
        int num = (*iter).first;
        int cnt = (*iter).second;

        if(visited[i]) {
            iter++;
            continue;
        }
        if(--cnt < 0) {
            cnt++;
            continue;
        }

        m_cnt[num]--;
        v.push_back(num);
        visited[i] = 1;

        dfs(cnt + 1);

        v.pop_back();
        visited[i] = 0;
        iter++;
    }
}


int main() {
    cin >> n >> m;

    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;

        if(m_cnt.find(tmp) == m_cnt.end()) { // 없을 때
            m_cnt.insert({tmp, 1});
        }
        else { 
            m_cnt[tmp] += 1;
        }
    }

    dfs(0);
}