#include <bits/stdc++.h>

using namespace std;

// b : 검은 공 & 상자 w : 흰 공 &  상자
// x : 검 / y : 흰 / z : 검 + 흰
int b, w, x, y, z;
bool visited[3] = {0,};
vector<pair<int, char>> v;

bool compare(pair<int, char> a, pair<int, char> b) {
	return a.first > b.first;
}

void input() {
	cin >> b >> w >> x >> y >> z;
}

int max_score = 0;
void dfs(int depth, int b_box, int b_ball, int w_box, int w_ball, int sum_score) {
	if(depth == 3) {
		max_score = max(max_score, sum_score);
		return;
	}

	for(int i = 0; i < 3; i++) {
		if(visited[i]) continue;
		visited[i] = 1;

		int nb_box = b_box, nb_ball = b_ball, nw_box = w_box, nw_ball = w_ball;
		int nsum_score = sum_score;

		if(i == 0) {
			// x
			int cnt_black = min(b_box, b_ball);
			sum_score += cnt_black * x;
			b_box -= cnt_black;
			b_ball -= cnt_black;
		}
		else if(i == 1) {
			// y
			int cnt_white = min(w_box, w_ball);
			sum_score += cnt_white * y;
			w_box -= cnt_white;
			w_ball -= cnt_white;
		}
		else {
			// z
			int cnt_mix1 = min(w_box, b_ball);
			int cnt_mix2 = min(w_ball, b_box);
			sum_score += (cnt_mix1 + cnt_mix2) * z;
			w_box -= cnt_mix1;
			b_ball -= cnt_mix1;
			w_ball -= cnt_mix2;
			b_box -= cnt_mix2;
		}
		dfs(depth + 1, b_box, b_ball, w_box, w_ball, sum_score);
		visited[i] = 0;
	}
}

void solve() {
	int score = 0;
	int b_ball = b, b_box = b;
	int w_ball = w, w_box = w;


	dfs(0, b_box, b_ball, w_box, w_ball, 0);
	cout << max_score << '\n';
}

int main() {
	int T, test_case;

	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		visited[0] = 0, visited[1] = 0, visited[2] = 0;
		input();
		solve();
	}
}