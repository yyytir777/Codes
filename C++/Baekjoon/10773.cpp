#include <iostream>
#include <stack>
using namespace std;

int arr[100000] = {0,};
stack<int> s;

int main(){
    int k;
    cin >> k;

    int tmp;
    int sum = 0;
    for(int i = 0; i < k; i++){
        cin >> tmp;

        if(tmp){
            s.push(tmp);
            sum += tmp;
        }
        else{
            sum -= s.top();
            s.pop();
        }
    }

    cout << sum << '\n';
    return 0;
}