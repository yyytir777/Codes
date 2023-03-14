#include <iostream>
#include <queue>
using namespace std;

struct compare{
    bool operator()(int &a, int &b){
        return a < b;
    }
};

priority_queue<int, vector<int>, compare> pq;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
        if(pq.size() % 2 != 0){ //사이즈가 홀수일 때
            int mid = (pq.size() - 1) / 2 + 1;
            cout << pq[mid] << '\n';
        }
        else{
            if()
            int mid = (pq.size() / 2)
        }
    }
    return 0;
}