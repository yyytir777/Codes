#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int cnt[MAX][MAX] = {0,};

pair<string, string> split(string gift) {
    string a, b;
    int tmp;
    for(int i = 0; i < gift.length(); i++) {
        if(gift[i] == ' ') {
            a = gift.substr(0, i);
            tmp = i;
        }
        
        if(i == gift.length() - 1) {
            b = gift.substr(tmp + 1);
        }
    }
    return {a,b};
}

void print(int l) {
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < l; j++) {
            cout << cnt[i][j] << " ";
        }
        cout << '\n';
    }
}

int getIndex(vector<string> friends, string name) {
    for(int i = 0; i < friends.size(); i++) {
        if(friends[i] == name) return i;
    }
}

vector<int> cal_ratio(int l) {
    vector<int> result(l,0);
    for(int i = 0; i < l; i++) {
        int sum = 0;
        for(int j = 0; j < l; j++) {
            sum += cnt[i][j];
        }
        result[i] += sum;
    }
    
    for(int j = 0; j < l; j++) {
        int sum = 0;
        for(int i = 0; i < l; i++) {
            sum += cnt[i][j];
        }
        result[j] -= sum;
    }
    
    return result;
}

int solution(vector<string> friends, vector<string> gifts) {
    int size = friends.size();
    
    for(auto gift : gifts) {
        pair<string, string> trans = split(gift);
        cnt[getIndex(friends, trans.first)][getIndex(friends, trans.second)] += 1;
    }
    
    // 선물지수 계산
    vector<int> gift_ratio = cal_ratio(size);
    
    vector<int> next_gift(size, 0);
    bool visited[MAX][MAX] = {0,};
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == j) continue;
            if(visited[i][j] || visited[j][i]) continue;
            
            visited[i][j] = 1; visited[j][i] = 1;
            
            // 선물지수 큰 사람이 선물
            if(cnt[i][j] == cnt[j][i] || cnt[i][j] + cnt[j][i] == 0) {
                if(gift_ratio[i] > gift_ratio[j]) {
                    next_gift[i] += 1;
                } else if(gift_ratio[j] > gift_ratio[i]) {
                    next_gift[j] += 1;
                }
            }
            
            // i가 더 선물을 많이했다면, i가 선물 받음
            if(cnt[i][j] > cnt[j][i]) {
                next_gift[i] += 1;
            } else if(cnt [j][i] > cnt[i][j]) {
                next_gift[j] += 1;
            }
        }
    }
    
    // for(int i = 0; i < size; i++) {
    //     cout << next_gift[i] << " ";
    // }
    
    sort(next_gift.begin(), next_gift.end());
    return next_gift[size - 1];
}