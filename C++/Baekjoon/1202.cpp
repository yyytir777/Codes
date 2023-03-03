#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> jewel;
vector<int> bag;
priority_queue<int> q;

int main(){

    int n, k; //n = 보석개수, k = 가방개수
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int m, v; //m = 무게, v = 가격
        cin >> m >> v;
        jewel.push_back(make_pair(m, v));
    }

    for(int i = 0; i < k; i++){
        int c; //c = 가방 최대 무게
        cin >> c;
        bag.push_back(c);
    }

    sort(jewel.begin(), jewel.end()); // 가격순 -> 가벼운순

    sort(bag.begin(), bag.end()); // 가벼운순

    int idx = 0;
    long long cost = 0;
    for(int i = 0; i < k; i++){
        while(idx < n && jewel[idx].first <= bag[i]){
            q.push(jewel[idx++].second);
        }

        if(!q.empty()){
        cost += q.top();
        q.pop();
        }
    }

    cout << cost;
    return 0;
}   