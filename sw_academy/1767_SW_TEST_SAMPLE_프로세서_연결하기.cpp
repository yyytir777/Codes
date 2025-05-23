#include <iostream>
#include <vector>
#define MAX 12
#define CELL 0
#define CORE 1
#define EDGE 2
using namespace std;

int tc, n;
int arr[MAX][MAX] = {0,};
int max_core = 0, min_edge = 987654321;
vector<pair<int, int>> cores;

int row_axis[4] = {1, -1, 0, 0};
int col_axis[4] = {0, 0, 1, -1};

void init_val() {
	cores.clear();
	max_core = 0;
	min_edge = 987654321;
}

void input() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == CORE && 
				!(i == 0 || j == 0 || i == n - 1 || j == n - 1)) {
				cores.push_back({i, j});
			}
		}
	}
}

bool possible(int x, int y, int d) {
	while(true) {
		x += row_axis[d];
		y += col_axis[d];

		if(arr[x][y] == EDGE || arr[x][y] == CORE) return false;
		if(arr[x][y] == 0 
			&& (x == 0 || y == 0 || x == n - 1 || y == n - 1)) break;
	}

	return true;
}

int setEdge(pair<int, int> pos, int d) {
	int cnt = 0;
	int x = pos.first;
	int y = pos.second;
	while(true) {
		x += row_axis[d];
		y += col_axis[d];
		if(x < 0 || y < 0 || x > n - 1 || y > n - 1) break;
		arr[x][y] = EDGE;
		cnt++;
	}
	return cnt;
}

void resetEdge(pair<int, int> pos, int d) {
	int x = pos.first;
	int y = pos.second;
	while(true) {
		x += row_axis[d];
		y += col_axis[d];
		if(x < 0 || y < 0 || x > n - 1 || y > n - 1) break;
		arr[x][y] = CELL;
	}
}

void dfs(int depth, int cnt_core, int cnt_edge) {
	if(depth == cores.size()) {
		if(cnt_core > max_core) {
			max_core = cnt_core;
			min_edge = cnt_edge;
		}
		else if(cnt_core == max_core) {
			min_edge = min(min_edge, cnt_edge);
		}
		return;
	}

	for(int i = 0; i < 4; i++) {
		if(possible(cores[depth].first, cores[depth].second, i)) {
			int cnt = setEdge(cores[depth], i);
			dfs(depth + 1, cnt_core + 1, cnt_edge + cnt);
			resetEdge(cores[depth], i);
		}
	}

	dfs(depth + 1, cnt_core, cnt_edge);
}

void print_v() {
	for(auto core : cores) {
		printf("%d %d\n", core.first, core.second);
	}
}

void solve() {
	dfs(0, 0, 0);
}

int main() {
	int num = 0;
	cin >> tc;
	for(int i = 1; i <= tc; i++) {
		init_val();
		input();
		solve();
		printf("#%d %d\n", i, min_edge);
	}
	return 0;
}