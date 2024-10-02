#include <bits/stdc++.h>
using namespace std;

int n;
int letter[26] = {0,};

bool compare(int a, int b) {
    if(a > b) return true;
    else return false;
}

int main() {
    cin >> n;
    string tmp;    

    for(int i = 0; i < n; i++) {
        cin >> tmp;

        int mul = 1;
        for(int j = tmp.size() - 1; j >= 0; j--) {
            letter[tmp[j] - 'A'] += mul;
            mul *= 10;
        }
    }

    sort(letter, letter+26, compare);

    // for(int i = 0; i < 10; i++) {
    //     cout << letter[i] << '\n';
    // }

    int result = 0, w = 9;
    for(int i = 0; i < 10; i++) {
        if(letter[i] == 0) continue;
        result += letter[i] * w--;
    }

    cout << result;

    return 0;
}