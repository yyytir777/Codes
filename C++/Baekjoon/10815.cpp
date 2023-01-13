#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cnt_n;
    cin >> cnt_n;
    //cnt_n : 배열arr_n의 크기

    int arr_n[cnt_n];
    //배열 arr_n 선언(상근이의 숫자카드)

    for(int i = 0; i < cnt_n; i++){
        cin >> arr_n[i];
    }

    int cnt_m;
    cin >> cnt_m;
    //cnt_m : 배열 arr_m의 크기

    int arr_m[cnt_m];
    //배열 arr_m 선언(정수 M개)

    for(int i = 0; i < cnt_m; i++){
        cin >> arr_m[i];
    }

    int arr_boolean[cnt_m] = {0};
    //arr_boolean : 상근이가 숫자카드를 가지고있는지 여부

    for(int i = 0; i < cnt_n; i++){
        for(int j = 0; j < cnt_m; j++){
            if (arr_n[i] == arr_m[j]){
                arr_boolean[j] = 1;
                break;
            }
        }
    }

    for(int i = 0; i < cnt_m; i++){
        cout << arr_boolean[i] << " ";
    }
    //arr_boolean 출력

    return 0;
}