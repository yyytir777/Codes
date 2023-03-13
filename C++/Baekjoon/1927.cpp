#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(num == 0 && q.empty()){
            cout << 0 << '\n';
        }
        else if(num == 0 && q.empty() == false){
            cout << q.top() << '\n';
            q.pop();
        }
        else q.push(num);
    }
    return 0;
}