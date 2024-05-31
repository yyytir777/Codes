#include <iostream>
#include <map>
#include <queue>
using namespace std;

                //<num, 넣은 순서>
priority_queue<pair<int, int>> max_pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
// <넣은 순서, num>
map<int, int> m;

void clear() {
    while(!max_pq.empty()) {
        max_pq.pop();
    }

    while(!min_pq.empty()) {
        min_pq.pop();
    }

    m.clear();
}

bool search(int n) {
    return m[n] > 0;
}

void insert(int num, int n) {
    max_pq.push({num, n});
    min_pq.push({num, n});
    m[n] = 0;
}

void deleteMax() {
    while(!max_pq.empty()) {
        pair<int, int> element = max_pq.top();
        max_pq.pop();

        if(!search(element.second)) { //삭제된 요소가 아닐 때
            m[element.second] = 1;
            break;
        }
    }
}

void deleteMin() {
    while(!min_pq.empty()) {
        pair<int, int> element = min_pq.top();
        min_pq.pop();

        if(!search(element.second)) { //삭제된 요소가 아닐 때
            m[element.second] = 1;
            break;
        }
    }
}

int main() {
    int T, cnt;
    cin >> T;

    for(int i = 0; i < T; i++) {
        
        cin >> cnt;
        
        int n = 0;
        for(int j = 0; j < cnt; j++) {
            char tmp;
            int num;
            cin >> tmp >> num;

            if(tmp == 'I')
                insert(num, n++);
            else if(tmp == 'D') {
                if(num == 1) deleteMax();
                else if(num == -1) deleteMin();
            }
        }

        int max, min;
        bool isEmpty = true;
        while(!max_pq.empty()) {
            pair<int, int> element = max_pq.top();

            if(search(element.second)) {
                max_pq.pop();
            }
            else {
                isEmpty = false;
                max = element.first;
                break;
            }
        }

        if (isEmpty) {
            cout << "EMPTY\n";
            clear();
            continue;
        }

        while(!min_pq.empty()) {
            pair<int, int> element = min_pq.top();

            if(search(element.second)) {
                min_pq.pop();
            }
            else {
                min = element.first;
                break;
            }
        }


        cout << max << " " << min << '\n';

        clear();
    }
}