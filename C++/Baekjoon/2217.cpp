#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> v_min;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        v_min.push_back(v[i] * (v.size() - i));
    }

    cout << *max_element(v_min.begin(), v_min.end());
    return 0;
}