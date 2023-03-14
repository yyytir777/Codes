#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    cin >> m >> n;

    int arr[n+1] = {0,};

    for(int i = 2; i <= n; i++){
        arr[i] = i;
    }

    for(int i = 2; i * i <= n; i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = i * 2; j <= n; j += i){
            arr[j] = 0;
        }
    }

    for(int i = m; i <= n; i++){
        if(arr[i] != 0){
            cout << i << '\n';
        }
    }
    
    return 0;
}