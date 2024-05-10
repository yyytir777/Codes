#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 500001
using namespace std;

int arr[MAX];
vector<int> array_list;
vector<pair<int, int>> cnt;
vector<int> sort_array;
vector<int> not_duplicate;
int num[8001] = {0,};

bool compare(pair<int, int> i,pair<int, int> j) {
    if(i.first == j.first) return i.second < j.second;
    else return j.first < i.first;
}

int main(){
    int N;
    cin >> N;

    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
        array_list.push_back(arr[i]);

        bool tmp = 0;
        for(auto a : not_duplicate) {
            if(arr[i] == a) {
                tmp = 1;
                break;
            }
        }
        if(tmp == 0) not_duplicate.push_back(arr[i]);
    }

    // 첫 번째 줄
    if(round((float)sum / N) == -0) cout << "0" << endl;
    else cout << round((float)sum / N) << endl; 

    //두 번째 줄
    sort(array_list.begin(), array_list.end());

    int mid = ((N - 1) / 2);
    cout << array_list[mid] << endl;

    for(int i = 0; i < N; i++) {
        int number = arr[i];
        num[4000 + number] += 1;
    }
    // {빈도, 값}
    for(auto number : not_duplicate) {
        cnt.push_back({num[4000 + number], number});
    }

    sort(cnt.begin(), cnt.begin() + not_duplicate.size(), compare);

    int idx = 0;
    while(true) {
        int min = cnt[idx].first;
        int next = cnt[idx+1].first;

        if(min == next) {
            sort_array.push_back(cnt[idx].second);
            idx++;
        }
        else {
            sort_array.push_back(cnt[idx].second);
            break;
        }
    }

    sort(sort_array.begin(), sort_array.end());

    if(sort_array.size() == 1) {
        cout << sort_array[0] << endl;
    }
    else {
        cout << sort_array[1] << endl;
    }

    cout << array_list[N-1] - array_list[0];
}