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
        cin >> end >> start;
        arr[i] = make_pair(end, start);
    }

    sort(arr, arr+n, greater<int>());

    int cnt = 0;
    int firstEndTime = arr[0].first;
    for(int i = 0; i < n; i++) {
        if(arr[i].second >= firstEndTime) {
            cnt++;
            firstEndTime = arr[i].first;
        }
    }

    cout << cnt;
}