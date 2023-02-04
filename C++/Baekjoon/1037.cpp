#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int cnt;
    cin >> cnt;

    vector <int> v;
    int number;
    for(int i = 0; i < cnt; i++){
        cin >> number;
        v.push_back(number);
    }


    sort(v.begin(), v.end());


    
    vector<int>::iterator iter;
    int min, max;
    min = v.front();
    max = v.back();

    cout << min * max;
    return 0;
}