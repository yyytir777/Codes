#include <iostream>
#include <deque>
using namespace std;

deque<int> d;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        d.push_back(i);
    }
    
    if(d.size() == 1){
        cout << "1";
        return 0;
    }

    while(true){
        d.pop_front();
        if(d.size() == 1){
            cout << d.front();
            return 0;
        }
        int tmp = d.front();
        d.push_back(tmp);
        d.pop_front();
    }
    return 0;
}