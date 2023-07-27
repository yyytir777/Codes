#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    queue<int> q;
    int n;
    cin >> n;

    string cmd;
    for(int i = 0; i < n; i++){
        cin >> cmd;

        if(cmd == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(cmd == "pop") {
            if(!q.empty()){
                cout << q.front() << '\n';
                q.pop();
            }
            else
                cout << "-1\n";
        }

        else if(cmd == "size")
            cout << q.size() << '\n';

        else if(cmd == "empty"){
            cout << q.empty() <<'\n';
        }

        else if(cmd == "front"){
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.front() << '\n';
        }

        else if(cmd == "back"){
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.back() << '\n';
        }
    }
    return 0;
}