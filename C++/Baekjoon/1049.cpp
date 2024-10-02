#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> price; // <패키지 가격, 낱개 가격>

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        price.push_back(tmp);
    }

    int min_package_idx = m - 1;
    int min_each_idx = m - 1;
    for(int i = 0; i < m; i++) {
        if(price[i].first < price[min_package_idx].first) min_package_idx = i;
        if(price[i].second < price[min_each_idx].second) min_each_idx = i;
    }

    int rest = n;
    int cost = 0;
    while(rest > 0) {
        if(rest >= 6) {
            cost += min(price[min_package_idx].first, price[min_each_idx].second * 6);
            rest -= 6;
        }
        else {
            cost += min(price[min_package_idx].first, price[min_each_idx].second * rest);
            rest -= rest;
        }
    }

    cout << cost;

    return 0;
}