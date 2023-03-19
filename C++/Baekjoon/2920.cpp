#include <iostream>
using namespace std;

int main(){
    int arr[8] = {0,};
    for(int i = 0; i < 8; i++){
        cin >> arr[i];
    }

    if(arr[0] < arr[1] && arr[1] < arr[2] && arr[2] < arr[3] && arr[3] < arr[4] && arr[4] < arr[5] && arr[5] < arr[6] && arr[6] < arr[7]){
        cout << "ascending" << '\n';
    }
    else if(arr[0] > arr[1] && arr[1] > arr[2] && arr[2] > arr[3] && arr[3] > arr[4] && arr[4] > arr[5] && arr[5] > arr[6] && arr[6] > arr[7]){
        cout << "descending" << '\n';
    }
    else{
        cout << "mixed" << '\n';
    }

    return 0;
}