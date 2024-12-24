#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> input_word;
map<string, int> dic;

void input() {
	cin >> n >> m;

	string tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		if(tmp.length() < m) continue;

		if(dic.find(tmp) == dic.end()) {
			dic[tmp] = 1;
			input_word.push_back(tmp);
		}
		else dic[tmp]++;
	}
}

bool compare(string word1, string word2) {

	if(dic[word1] != dic[word2]) return dic[word1] > dic[word2];

	if(word1.length() != word2.length()) return word1.length() > word2.length();

	return word1 < word2;
}

void solve() {
	sort(input_word.begin(), input_word.end(), compare);

	for(string word : input_word) {
		cout << word << '\n';
	}
}

int main() {
	cin.tie(NULL);

	input();
	solve();
}