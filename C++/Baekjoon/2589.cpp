#include <bits/stdc++.h>
#define MAX 51
#define L 0
#define W 1
using namespace std;

int r, c;
int graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};
int dist[MAX][MAX];
vector<int> minDistCandidate;
queue<pair<int, int>> q;

int row_axis[4] = {0, 0, -1, 1};
int col_axis[4] = {1, -1, 0, 0};

void init() {
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			visited[i][j] = 0;
			dist[i][j] = 0;
		}
	}
}

void input() {
	cin >> r >> c;
	char input;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> input;
			if(input == 'W') graph[i][j] = W;
			else if(input == 'L') graph[i][j] = L;
		}
	}
}

void printGraph() {
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}	
}

void bfs(pair<int, int> start) {
	q.push(start);
	visited[start.first][start.second] = 1;
	dist[start.first][start.second] = 0;

	while(!q.empty()) {
		pair<int, int> cur_node = q.front();
		q.pop();

		for(int i = 0; i < 4; i++) {
			int nxt_row = cur_node.first + row_axis[i];
			int nxt_col = cur_node.second + col_axis[i];

			if(nxt_row < 0 || nxt_row >= r || nxt_col < 0 || nxt_col >= c) continue;

			if(graph[nxt_row][nxt_col] == L && !visited[nxt_row][nxt_col]) {
				q.push({nxt_row, nxt_col});
				visited[nxt_row][nxt_col] = 1;
				dist[nxt_row][nxt_col] = dist[cur_node.first][cur_node.second] + 1;
			}
		}
	}
}

pair<int, int> findMaxDist() {
	int max_dist = 0;
	pair<int, int> pos;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(max_dist < dist[i][j]) {
				max_dist = dist[i][j];
				pos = {i,j};
			}
		}
	}
	return pos;
}

void solve() {
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(graph[i][j] == L && !visited[i][j]) {
				cout << "r : " << i << " c : " << j << '\n';
				bfs({i, j});
				pair<int, int> start = findMaxDist();
				init();
				bfs(start);
				printGraph();
			}
		}
	}
}

int main() {
	input();
	solve();
	return 0;
}