  // 2504 cpp
#include <bits/stdc++.h>
#define MAX 31
using namespace std;

string str;
int temp = 1;
stack<char> s;

void input() {
    cin >> str;
}    


void solve() {
    int ans = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            s.push('(');
            temp *= 2;
        } 
        else if(str[i] == '[') {
            s.push('[');
            temp *= 3;
        }

        else if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {
                ans = 0;
                break;
            }

            if(str[i-1] == '(') {
                ans += temp;
            }
            temp /= 2;
            s.pop();
        }

        else if(str[i] == ']') {
            if(s.empty() || s.top() != '[') {
                ans = 0;
                break;
            }

            if(str[i-1] == '[') {
                ans += temp;
            }
            temp /= 3;
            s.pop();
        }
    }

    if(!s.empty()) ans = 0;

    cout << ans;
}

int main() {
    input();
    solve();
    return 0;
}