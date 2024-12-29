#include <bits/stdc++.h>
using namespace std;

int s, p;
string dna;
char dna_info[4] = {'A', 'C', 'G', 'T'};
map<char, int> dna_map, partial_map;

void input() {
	cin >> s >> p;
	cin >> dna;

	int temp;
	for(int i = 0; i < 4; i++) {
		cin >> temp;
		dna_map[dna_info[i]] = temp;
	}
}

void calcPartialString(int idx) {

	// 처음 부분 문자열을 사용할 때는 전체를 iter
	if(idx == 0) {
		string res = "";
		for(int i = 0; i < p; i++) {
			res += dna[i];
			partial_map[dna[i]]++;
		}
	}

	// 중간의 부분 문자열을 사용할 때는 양 끝만 고려
	else {
		partial_map[dna[idx - 1]]--;
		partial_map[dna[idx - 1 + p]]++;
	}

	// cout << "calc Partial String : ======" << '\n';
	// for(auto element : partial_map) {
	// 	cout << element.first << " : " << element.second << '\n';
	// }
}

bool canMakePassword() {
	for(int i = 0; i < 4; i++) {
		if(dna_map[dna_info[i]] > partial_map[dna_info[i]]) return false;
	}
	return true;
}

void solve() {
	int cnt = 0;

	for(int i = 0; i < 4; i++) partial_map[dna_info[i]] = 0;

	for(int i = 0; i <= s - p; i++) {
		calcPartialString(i); // partial_map 업데이트
		if(canMakePassword()) cnt++;
	}
	cout << cnt;
}

int main() {
	input();
	solve();
	return 0;
}