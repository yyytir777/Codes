#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int cnt;
    cin >> cnt;
    //n = 배열의 크기

    int arr_A[50];
    int arr_B[50];
    // 배열 선언

    for(int i = 0; i < cnt; i++){
        cin >> arr_A[i];
    }

    for(int i = 0; i < cnt; i++){
        cin >> arr_B[i];
    }

    sort(arr_A, arr_A + cnt);
    sort(arr_B, arr_B + cnt);
    int result = 0;
    int add;
    for(int i = 0; i < cnt; i++){
        add = arr_A[i] * arr_B[cnt - 1 - i];
        result += add;
    }

    cout << result;

}