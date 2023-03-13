#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, bool>> pq;//ture = + & false = -


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
                pq.push(make_pair(x, 0));
            }
            else if(x < 0){
                pq.push(make_pair(x, 1));
            }
        }
        else{ // x == 0
            if(pq.empty()){
                cout << "0" << '\n';
                continue;
            }
            else{
                if(pq.top().second == 0){
                    cout << pq.top().first << '\n';
                }
                else if(pq.top().second == 1){
                    cout << pq.top().first << '\n';                    
                }
                pq.pop();
            }
        }
    }
    return 0;
}