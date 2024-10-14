#include <bits/stdc++.h>
using namespace std;

int main() {
    string word, boom_word;
    cin >> word >> boom_word;

    stack<char> s;
    for(int i = 0; i < word.size(); i++) {
        s.push(word[i]);
        if(s.size() < boom_word.size()) continue;

        // boom_word 개수만큼 s에서 가져감
        string tmp = "";
        for(int i = 0; i < boom_word.size(); i++) {
            char letter = s.top();
            s.pop();
            tmp += letter;
        }

        reverse(tmp.begin(), tmp.end());

        if(tmp != boom_word) { // boom_word가 아니면
            for(int j = 0; j < tmp.size(); j++) {
                s.push(tmp[j]);
            }
        }
    }

    vector<char> v;
    while(!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    
    reverse(v.begin(), v.end());

    if(v.empty()) cout << "FRULA";
    else {
        for(char word : v) {
            cout << word;
        }
    }
}