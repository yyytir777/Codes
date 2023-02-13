#include <iostream>
using namespace std;

#define N 11
int arr[N];

int main(){
    int n, k;
    int cnt = 0;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int a = n - 1;
    while(a >= 0){
        if(arr[a] <= k){
            int b = k / arr[a];
            cnt += b;
            k -= (b * arr[a]);
        }
        a--;
    }

    cout << cnt;

    return 0;
}