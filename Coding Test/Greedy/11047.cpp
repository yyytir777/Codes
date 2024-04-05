#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, k;

void input() {
    cin >> n >> k;
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<int>());
}

void greedy(int k) {
    vector<int>::iterator iter;
    iter = v.begin();

    int value = 0;
    int cnt = 0;
    while(k != value) {
        /* 가장 큰 값을 더했을 때의 가치가 k보다 크거나 같으면 
        iter를 전 인덱스로 옮기고 continue */
        if(value + *iter > k) {
            iter++;
        }
        /* 가장 큰 값을 더했을 때의 가치가 k보다 작으면 value에
        해당 값을 더함 */
        else {
            value += *iter;
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    input();
    greedy(k);
}