#include <iostream>
using namespace std;

int arr[41] = {};

int fibonacci(int n) {
    if (n <= 1) {
        arr[n] = n;
        return arr[n];
    }

    if(arr[n] != 0)
        return arr[n];

    arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return arr[n];
}


int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        fibonacci(a);
        if(a == 0){
            cout << "1 0" << '\n';
        }
        else if(a == 1){
            cout << "0 1" << '\n';
        }
        else{
            cout << arr[a-1] << " " << arr[a] << '\n';
        }   
    }
    return 0;
}