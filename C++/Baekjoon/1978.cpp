#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = n;
    int *arr_n = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr_n[i];
        if(arr_n[i] == 1){
            cnt--;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 2; j < arr_n[i]; j++){
            if(arr_n[i] % j == 0){ //¼Ò¼öX
                cnt--;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}