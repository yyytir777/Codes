#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 500001
using namespace std;

int arr[MAX];
vector<int> array;
vector<pair<int, int>> cnt;
int num[8001] = {0,};

bool compare(pair<int, int> i,pair<int, int> j) {
    if(i.first == j.first) return j.second < i.second;
    else return j < i;
}

int main(){
    int N;
    cin >> N;

    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
        array.push_back(arr[i]);
    }

    // 첫 번째 줄
    cout << round((float)sum / N) << endl; 

    //두 번째 줄
    cout << arr[(N - 1) / 2 + 1] << endl;

    for(auto number : arr) {
        num[number] += 1;
    }

    for(int i = 0; i < N; i++) {
        cnt.push_back({num[i], i});
    }

    sort(cnt.begin(), cnt.end(), compare);

    if(cnt.size() == 1) {
        cout << cnt.front().second << endl;
    }
    else {
        cout << cnt[1].second << endl;
    }

    sort(array.begin(), array.end());

    cout << array[N-1] - array[0];
}