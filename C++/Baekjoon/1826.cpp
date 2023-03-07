#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int fuel_station[1000001] = {0,};
priority_queue<int> q;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        fuel_station[a] = b;
    }

    int l, p; //l = 마을거리, p = 원래 있던 연료 양
    cin >> l >> p;
   
    int fuel = p;
    int answer = 0;

    for(int i = 1; i < l; i++){
        fuel -= 1;
        if(fuel_station[i] != 0){
            q.push(fuel_station[i]);
        }
        
        if(fuel == 0){
            if(q.empty()){
                cout << "-1";
                return 0;
            }
            else{
                answer++;
                fuel += q.top();
                q.pop();
            }
        }
    }

    cout << answer << '\n';
    return 0;
}