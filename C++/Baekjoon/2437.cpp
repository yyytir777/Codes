// 2437 cpp
#include <bits/stdc++.h>
#define ll long
#define MAX 1001
using namespace std;


int n;
int arr[MAX];

void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    sort(arr, arr+n);

    ll sum = 0, ans = 0;

    if(arr[0] > 1) {
        cout << ans + 1;
        return;
    }

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(i == n-1) {
            ans = sum + 1;
            break;
        }

        if(sum + 1 < arr[i+1]) {
            ans = sum + 1;
            break;
        }
    }

    cout << ans;
}

void print() {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    input();
    solve();
    // print();
    return 0;
}