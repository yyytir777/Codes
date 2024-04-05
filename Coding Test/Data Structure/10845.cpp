#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        if(tmp == "push") {
            int value;
            cin >> value;
            q.push(value);
        }
        else if(tmp == "pop") {
            if(!q.size()) cout << "-1" << endl;
            else {
                int result = q.front();
                q.pop();
                cout << result << endl;
            }
        }
        else if(tmp == "size") {
            cout << q.size() << endl;
        }
        else if(tmp == "empty") {
            cout << q.empty() << endl;
        }
        else if(tmp == "front") {
            if(!q.size()) cout << "-1" << endl;
            else {
                cout << q.front() << endl;
            }
        }
        else if(tmp == "back") {
            if(!q.size()) cout << "-1" << endl;
            else {
                cout << q.back() << endl;
            }
        }
    }
}