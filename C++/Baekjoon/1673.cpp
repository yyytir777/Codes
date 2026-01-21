// 1673 cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

void solve() {
	ll sum = 0;
	while(n > 0) {
		sum += n;
		n = (n / k);
	}
	cout << sum << '\n';
}

int main() {
	while(scanf("%lld %lld", &n, &k) != EOF) {
		solve();
	}
	return 0;
}