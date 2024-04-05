#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;

    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        if(tmp == "push") {
            int value;
            cin >> value;

            s.push(value);
        }
        else if(tmp == "pop") {
            if(!s.size()) cout << "-1" << endl;
            else {
                int result = s.top();
                s.pop();
                cout << result << endl;
            }
        }
        else if(tmp == "size") {
            cout << s.size() << endl;
        }
        else if(tmp == "empty") {
            cout << s.empty() << endl;
        }
        else if(tmp == "top") {
            if(!s.size()) cout << "-1" << endl;
            else {
                cout << s.top() << endl;
            }
        }
    }
}