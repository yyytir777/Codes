#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

vector<int> time;
int main() {
    int N;
    cin >> N;

    int tmp;
    for(int i = 1; i <= N; i++) {
        cin >> tmp;
        time.push_back(tmp);
    }

    sort(time.begin(), time.end());

    int tmp_sum = 0, sum = 0;
    for(int i = 0; i < N; i++) {
        tmp_sum += time[i];
        sum += tmp_sum;
    }
    cout << sum;
}