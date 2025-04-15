// 15683 cpp
#include <bits/stdc++.h>
#define MAX 9
#define BLANK 0
#define WALL 6
#define VISITED -1
#define INF 987654321
using namespace std;

typedef pair<int, int> Pair;


int n, m;
int min_cctv = INF;
int arr[MAX][MAX];
int tmp[MAX][MAX][MAX];

// 북 동 남 서 <- 로 변경
int axis_r[4] = {0, 1, 0, -1};
int axis_c[4] = {1, 0, -1, 0};
vector<pair<int, Pair>> cctv;

void reach(int r, int c, int d) {
	d %= 4;

	while(true) {
		r += axis_r[d];
		c += axis_c[d];

		if(r < 0 || c < 0 || r >= n || c >= m) return;
		if(arr[r][c] == WALL) return;
		if(0 < arr[r][c] && arr[r][c] < 6) continue;
		if(arr[r][c] == VISITED) continue;
		arr[r][c] = VISITED;
	}
}

void input() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <  m; j++) {
			cin >> arr[i][j];
		}
	}
}

int getCountOfBlank() {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == BLANK) cnt++;
		}
	}
	return cnt;
}

void copy(int depth) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			tmp[depth][i][j] = arr[i][j];
	}
}

void paste(int depth) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			arr[i][j] = tmp[depth][i][j];
	}
}

void print_arr() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << "\n\n";
}

/* 
dfs는 recursive를 통해 구현
parameter : 방문한 cctv 개수
cctv개수가 전체 개수일 경우 가장 적은 사각지대 거리 return
*/
void dfs(int cctv_index) {
	// print_arr();

	if(cctv_index == cctv.size()) {
		int cnt = getCountOfBlank();
		min_cctv = min(min_cctv, cnt);
		return;
	}

	Pair node = cctv[cctv_index].second;
	int d = cctv[cctv_index].first;
	int i = node.first, j = node.second;


	for(int d = 0; d < 4; d++) {
		copy(cctv_index);

		if(arr[i][j] == 1) {
			reach(i, j, d + 1);
		}
		else if(arr[i][j] == 2){
			reach(i, j, d + 1);
			reach(i, j, d + 3);
		}
		else if(arr[i][j] == 3) {
			reach(i, j, d);
			reach(i, j, d + 1);
		}
		else if(arr[i][j] == 4) {
			reach(i, j, d);
			reach(i, j, d + 1);
			reach(i, j, d + 3);
		}
		else {
			reach(i, j, d);
			reach(i, j, d + 1);
			reach(i, j, d + 2);
			reach(i, j, d + 3);
		}

		dfs(cctv_index + 1);

		paste(cctv_index);
	}
}

void solve() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(0 < arr[i][j] && arr[i][j] < 6) {
				cctv.push_back({arr[i][j], {i, j}});
			}
		}
	}

	dfs(0);
	cout << min_cctv << '\n';
}


int main() {
	input();
	solve();
	return 0;
}