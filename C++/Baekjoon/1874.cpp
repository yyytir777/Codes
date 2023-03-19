#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        s.push(tmp);
    }

    
    return 0;
}