#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

pair<int, int> arr[MAX];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int end, start;
        cin >> start >> end;
        arr[i] = make_pair(end, start);
    }

    sort(arr, arr+n);

    int cnt = 1;
    int firtEndTime = arr[0].first;
    for(int i = 1; i <= n; i++) {
        if(firtEndTime <= arr[i].second) {
            cnt++;
            firtEndTime = arr[i].first;
        }
    }

    cout << cnt;
}