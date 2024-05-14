#include <iostream>
using namespace std;

long long N, k;

int main() {
    cin >> N;
    cin >> k;

    long long start = 1;
    long long end = N * N;
    long long mid, answer, cnt;

	while (start <= end) {
        cnt = 0;
		mid = (start + end) / 2;

		for (long long i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
		
		if (cnt < k) start = mid + 1;
		else {
            answer = mid;
            end = mid - 1;
        }
	}
    cout << answer;
}