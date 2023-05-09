#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

vector<int> v;
int arr[MAX] = {0,};

bool check(int n){
    int sum = 0;
    int j = 0;
    while(true){
        if(arr[j] > n){
            return false;
        }
        if(n != sum){
            sum += arr[j];
            j++;
        }
        else{
            return true;
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    vector<int>::iterator iter;
    int i = 0;
    for(iter = v.begin(); iter != v.end(); iter++){
        arr[i] = *iter;
        i++;
    }

    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}