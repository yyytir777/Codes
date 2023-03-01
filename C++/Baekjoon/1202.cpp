#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> jewel;
vector<int> bag;


bool compare_jewel(pair<int, int> jewel_1, pair<int, int> jewel_2){ //first = 무게, second = 가격
    if(jewel_1.first == jewel_2.first){
        return jewel_1.second > jewel_2.second;
    }
    return jewel_1.second > jewel_2.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

    sort(jewel.begin(), jewel.end(), compare_jewel); // 가격순 -> 가벼운순

    sort(bag.begin(), bag.end()); // 가벼운순

    int i = 0, cost = 0;
    while(!bag.empty()){
        if(jewel[i].first <= bag[i]){
            cost += jewel[i].second;
            jewel.erase(jewel.begin() + i);
            bag.erase(bag.begin() + i);
        }
    }

    cout << cost;
    return 0;
}   