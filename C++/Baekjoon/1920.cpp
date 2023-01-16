#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector <int> vector_n;
    int n;
    cin >> n;

    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        vector_n.push_back(tmp);
    }
    //N개 vector로 받음

    sort(vector_n.begin(), vector_n.end());
    //vector 정렬

    int m;
    cin >> m;

    int arr_m[m];
    for(int i = 0; i < m; i++){
        cin >> arr_m[i];
    }

    int arr[m];

    for(int i = 0; i < m; i++){
        if(binary_search(vector_n.begin(), vector_n.end(), arr_m[i])){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }

    for(int i = 0; i < m ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}