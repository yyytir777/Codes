#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int n;
int arr[MAX];

void input() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

bool compare(int a, int b) {
	return a > b;
}

void print() {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void solve() {
	sort(arr, arr+n, compare);
	// print();

	int i = 0, sum = 0;
	while(i < n) {
		if(n - i == 1) {
			sum += arr[i++];
		}
		else if(n - i == 2) {
			sum += max(arr[i] + arr[i+1], arr[i] * arr[i+1]);
			i += 2;
		}
		else {
			int branch1 = max(arr[i] + arr[i+1] + arr[i+2], arr[i] * arr[i+1] + arr[i+2]);
			int branch2 = max(arr[i] + arr[i+1] + arr[i+2], arr[i] + arr[i+1] * arr[i+2]);

			if(branch1 >= branch2) {
				sum += branch1 - arr[i+2];
				i += 2;
			}
			else {
				sum += branch2;
				i += 3;
			}
		}
	}
	cout << sum;
}

int main() {
	input();
	solve();
	return 0;
}