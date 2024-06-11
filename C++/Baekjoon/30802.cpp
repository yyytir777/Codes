#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[6];
    for(int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    int t, p;
    cin >> t >> p;

    int sum_t = 0;
    for(int cnt : arr) {
        int tmp1 = (cnt / t);
        int tmp2 = (cnt % t == 0) ? 0 : 1;
        sum_t += tmp1 + tmp2;
    }
    cout << sum_t << '\n';

    cout << n / p << " " << n % p;
}