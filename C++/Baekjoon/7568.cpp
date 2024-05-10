#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

int arr[MAX];
vector<pair<int, int>> v;

int main(){
    int N;
    cin >> N;

    int w, h, size;
    for(int i = 0; i < N; i++) {
        cin >> w >> h;
        v.push_back({w, h});
    }

    for(int i = 0; i < N; i++) {
        int cnt = 1;
        for(int j = 0; j < N; j++) {
            if(v[i].first < v[j].first && v[i].second < v[j].second) cnt++;
        }
        cout << cnt << " ";
    }
}