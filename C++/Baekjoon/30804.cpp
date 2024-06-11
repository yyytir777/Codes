#include <bits/stdc++.h>
#define MAX 200002
using namespace std;

int fruit[12] = {0,};
int arr[MAX];
int max_cnt = 0;

int fruitSize() {
    int cnt = 0;
    for(bool tmp : fruit) {
        if(tmp) cnt++;
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int a = 0, b = 0;
    while(b < n) {
        fruit[arr[b]]++;

        while(fruitSize() > 2) {
            fruit[arr[a++]]--;
        }
        
        max_cnt = max(max_cnt, b - a + 1);
        b++;
    }

    cout << max_cnt;
}