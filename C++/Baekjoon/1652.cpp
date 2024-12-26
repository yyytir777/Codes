#include <bits/stdc++.h>
#define N 101
using namespace std;

char room[N][N];
int n;

void input() {
	cin >> n;

	char inputChar;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> inputChar;
			if(inputChar == '.') room[i][j] += '.';
			else if(inputChar == 'X') room[i][j] += 'X';
		}
	}
}

int canSleep(string str) {
	int cnt = 0, temp_cnt = 0;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == '.') temp_cnt++;
		else temp_cnt = 0;

		if(temp_cnt == 2) cnt++; 
	}
	return cnt;
}

void solve() {
	int row = 0, col = 0;

	// row
	for(int i = 0; i < n; i++) {
		string str = "";
		for(int j = 0; j < n; j++) {
			str += room[i][j];
		}

		int cnt = canSleep(str);
		if(cnt) {
			row += cnt;
		}
	}

	// column
	for(int i = 0; i < n; i++) {
		string str = "";
		for(int j = 0; j < n; j++) {
			str += room[j][i];
		}

		int cnt = canSleep(str);
		if(cnt) {
			col += cnt;
		}
	}

	cout << row << " " << col;
}

int main() {
	input();
	solve();
}