#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}

int main(){
    int cnt;
    cin >> cnt;

    pair<int, string> student;
    vector<pair<int, string>> v;

    for(int i = 0; i < cnt; i++){
        cin >> student.first >> student.second;
        v.push_back(student);
    }
    stable_sort(v.begin(), v.end(), compare);
    for(int i = 0; i < cnt; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}