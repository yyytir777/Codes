#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, bool>> q;
vector<int> v;

int main(){
    int cnt;
    int testCase;
    cin >> testCase;

    int N, M;
    for(int i = 0; i < testCase; i++) {
        v.clear();
        while (!q.empty()) q.pop();

        cin >> N >> M;

        int tmp, element;
        for(int j = 0; j < N; j++) {
            cin >> tmp;
            v.push_back(tmp);

            if(j == M) q.push(make_pair(tmp, 1));
            else q.push(make_pair(tmp, 0));
        }

        sort(v.begin(), v.end());

        cnt = 0;
        while(!q.empty()) {
            // 맨 앞의 우선순위가 최댓값이라면
            if(v.back() == q.front().first) {
                cnt++;
                if(q.front().second == 1) {
                    cout << cnt << endl;
                    break;
                }
                else {
                    v.pop_back();
                    q.pop();
                }
            }
            else {
                q.push(make_pair(q.front().first, q.front().second));
                q.pop();
            }
        }
    }
}