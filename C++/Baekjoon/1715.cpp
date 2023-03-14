#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct compare{
    bool operator()(int &a, int &b){
        return a > b;
    }
};

priority_queue<int, vector<int>, compare> pq;

int main(){
    int n;
    cin >> n;

    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        pq.push(tmp);
    }

    int sum = 0;
    while(!pq.empty()){
        if(pq.size() == 1){
            cout << 0 << '\n';
            return 0;
        }
        int tmp_a = pq.top();
        pq.pop();
        int tmp_b = pq.top();
        pq.pop();

        if(pq.empty()){
            int tmp_sum = tmp_a + tmp_b;
            sum += tmp_sum;
            break;
        }
        int tmp_sum = tmp_a + tmp_b;
        sum += tmp_sum;
        pq.push(tmp_sum);
    }

    cout << sum << '\n';
    return 0;
}