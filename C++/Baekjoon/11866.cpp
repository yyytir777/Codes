#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    cout << "<";

    while(q.size() != 0){
        for(int i = 1; i < k; i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if(q.size() != 1){
            cout << ", ";
        }
        q.pop();
    }
    cout << ">";
    return 0;
}