#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s;
    cin >> s;

    int n = 1, cnt = 0;
    while(s > 0) {
        s -= n++;
        cnt++;
    }

    if(s < 0) cnt--;
    
    cout << cnt;
}