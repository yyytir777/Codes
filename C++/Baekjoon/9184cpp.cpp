#include <bits/stdc++.h>
using namespace std;

int arr[21][21][21] = {0,};

int recurs(int a, int b, int c) {
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return recurs(20, 20, 20);

	if(arr[a][b][c] != 0) return arr[a][b][c];

	if (a < b && b < c) {
		arr[a][b][c] = recurs(a, b, c-1) + recurs(a, b-1, c-1) - recurs(a, b-1, c);
		return arr[a][b][c];
	}
	else {
		arr[a][b][c] = recurs(a-1, b, c) + recurs(a-1, b-1, c) + recurs(a-1, b, c-1) - recurs(a-1, b-1, c-1);
		return arr[a][b][c];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(true){ 
		int a, b, c; cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) {
			break;
		}

		int ans = recurs(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
	}

	return 0;
}