#include <bits/stdc++.h>
using namespace std;

string letter;

int main() {
    cin >> letter;

    char flag;
    int cnt = 0;
    for(int i = 0; i < letter.size() - 1; i++) {
        if(letter[i] != letter[i+1]) {
            flag = letter[i+1];
            cnt++;
        }
    }

    if(cnt % 2 == 0) cout << cnt / 2;
    else cout << cnt / 2 + 1;
    return 0;
}