#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack <int> s;
    for(int i = 0 ; i < n; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "pop")
        {
            if(s.empty() == 1){
                cout << "-1" << '\n';
            }
            else{
                cout << s.top() << '\n';
                s.pop();
            }
            
        }
        else if(cmd == "top")
        {   
            if(s.empty() == 1){
                cout << "-1" << '\n';
            }
            else{
                cout << s.top() << '\n';
            }
        }
        else if(cmd == "size")
        {   
            cout << s.size() << '\n';
        }
        else if(cmd == "empty")
        {
            cout << s.empty() << '\n';
        }
        else if(cmd == "push")
        {
            int x;
            cin >> x;
            s.push(x);
        }
    }
    return 0;
}