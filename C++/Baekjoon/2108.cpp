#include <iostream>
#include <algorithm>
using namespace std;

int arr[500000] ={0,};
bool check[500000] = {false,}

int main(){
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n);

    cout << (int)(sum / n);

    int mid = n / 2;

    cout << arr[mid];

}
