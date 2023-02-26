#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 100000
pair<int, int> time[N];
vector<pair<int, int>> v;
//끝나는 시간을 기준으로 sort -> 제일 마지막에 끝나는 시간을 기준으로 차례대로 cnt++ ....???

//내림차순으로 정렬
bool compare(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main(){
    int n, start, end;
    cin >> n;


    //배열에 시작시간 , 끝나는 시간을 pair로 입력받음
    for(int i = 0; i < n; i++){
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }

    //끝나는 시간이 큰 순서대로 정렬 > 시작하는 시간이 큰 순서대로 정렬
    sort(v.begin(), v.end(),compare);
    
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }

    int cnt = 0;
    int end_time;
    int start_time = v[0].first;

    for(int i = 1; i < n; i++){
        end_time = v[i].second;
        if(start_time <= end_time){
            cnt++;
            start_time = v[i].first;
        }
    }

    cout << cnt;
    return 0;
}