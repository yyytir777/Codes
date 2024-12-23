#include <bits/stdc++.h>
using namespace std;

int l, c;
char vowel_letters[5] = {'a','e','i','o','u'};
vector<char> possible_char;
vector<char> vowels;
vector<char> consonants;
vector<string> ans;

void charCount(char tmp) {
    for(char letter : vowel_letters) {
        if(tmp == letter) {
            vowels.push_back(tmp);
            return;
        }
    }
    consonants.push_back(tmp);
    return;
}

void input() {
    cin >> l >> c;

    char tmp;
    for(int i = 0; i < c; i++) {
        cin >> tmp;
        possible_char.push_back(tmp);
        charCount(tmp);
    }
}

void print() {
    for(char tmp : vowels) {
        cout << tmp << " ";
    }
    cout << '\n';

    for(char tmp : consonants) {
        cout << tmp << " ";
    }
    cout << '\n';
}

bool isVowel(char letter) {
    for(char tmp : vowel_letters) {
        if(letter == tmp) return true;
    }
    return false;
}

void dfs(vector<char> picked_letter, int length, int index, int vowel_cnt, int consonants_cnt) {
    if(length == l) {
        if(vowel_cnt >= 1 && consonants_cnt >= 2) {
            sort(picked_letter.begin(), picked_letter.end());

            string password = "";
            for(auto tmp : picked_letter) {
                password += tmp;
            }
            ans.push_back(password);
        }
        return;
    }

    for(int i = index; i < possible_char.size(); i++) {
        picked_letter.push_back(possible_char[i]);

        if(isVowel(possible_char[i])) dfs(picked_letter, length + 1, i + 1, vowel_cnt + 1, consonants_cnt);
        else dfs(picked_letter, length + 1, i + 1, vowel_cnt, consonants_cnt + 1);

        picked_letter.pop_back();
    }
}

void solve() {
    vector<char> picked_letter;
    dfs(picked_letter, 0, 0, 0, 0);

    sort(ans.begin(), ans.end());

    for(string tmp : ans) {
        cout << tmp << '\n';
    }
}

int main() {
    input();
    // print();
    solve();
}