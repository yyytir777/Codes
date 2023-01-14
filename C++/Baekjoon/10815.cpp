#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int cnt_n;
    cin >> cnt_n;
    //cnt_n : 배열arr_n의 크기

    vector <int> vector_n;

    for(int i = 0; i < cnt_n; i++){
        int n;
        cin >> n;
        vector_n.push_back(n);
    }
    //vector_n에 입력

    int cnt_m;
    cin >> cnt_m;
    //cnt_m : 배열 arr_m의 크기

    int arr_m[cnt_m];

    for(int i = 0; i < cnt_m; i++){
        cin >> arr_m[i];
        
    }

    //vector_m에 입력

    int arr_boolean[cnt_m];
    //arr_boolean : 상근이가 숫자카드를 가지고있는지 여부 크기 : cnt_m

    /*
    for(int i = 0; i < cnt_n; i++){
        for(int j = 0; j < cnt_m; j++){
            if (arr_n[i] == arr_m[j]){
                arr_boolean[j] = 1;
                break;
            }
        }
    }
    => 시간복잡도 : n^2 이므로 vector -> binary search 사용해야함
    */

    sort(vector_n.begin(), vector_n.end());
    //상근이의 카드 정렬

    for(int i = 0; i < cnt_m; i++){
        if(binary_search(vector_n.begin(), vector_n.end(), arr_m[i])){
            arr_boolean[i] = 1;
        }
        else{
            arr_boolean[i] = 0;
        }
    }
    //arr_boolean 입력

    for(int i = 0; i < cnt_m; i++){
        cout << arr_boolean[i] << " ";
    }
    //arr_boolean 출력
    return 0;
}