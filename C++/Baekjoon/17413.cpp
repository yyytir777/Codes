#include <bits/stdc++.h>
using namespace std;

void reverse(stack<char> &s) {
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    string S;
    getline(cin, S);

    stack<char> s;

    bool flag = 0;
    for(char letter : S) {
        if(letter == '<') {
            reverse(s);
            cout << letter;
            flag = 1;
        }
        else if(letter == '>') {
            flag = 0;
            cout << letter;
        }
        else if(flag) {
            cout << letter;
        }
        else if(letter == ' ') {
            reverse(s);
            cout << " ";
        }
        else {
            s.push(letter);
        }
    }
    reverse(s);
}