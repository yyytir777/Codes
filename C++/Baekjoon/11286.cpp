#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> v;//ture = + & false = -

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(x != 0){
            if(x >= 0){
                v.push(make_pair(x, 1)); // 1 -> 양수
            }
            else if(x < 0){
                v.push(make_pair(-x, 0)); // 0 -> 음수
            }
        }
        else{ // x == 0
            if(v.empty()){
                cout << "0" << '\n';
                continue;
            }
            else{
                if(v.top().second == 1){
                    cout << v.top().first << '\n';
                }
                else if(v.top().second == 0){
                    cout << -v.top().first << '\n';                    
                }
                v.pop();
            }
        }
    }
    return 0;
}