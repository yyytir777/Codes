#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    vector <int> v;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        bool cnt = 0;
        for(int j = 0; j < v.size(); j++){
            if(arr[i] == v[j]){
                cnt = 1;
            }
        }
        if(cnt == 0)
        v.push_back(arr[i]);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}