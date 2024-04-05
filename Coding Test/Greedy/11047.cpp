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
        /* ���� ū ���� ������ ���� ��ġ�� k���� ũ�ų� ������ 
        iter�� �� �ε����� �ű�� continue */
        if(value + *iter > k) {
            iter++;
        }
        /* ���� ū ���� ������ ���� ��ġ�� k���� ������ value��
        �ش� ���� ���� */
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