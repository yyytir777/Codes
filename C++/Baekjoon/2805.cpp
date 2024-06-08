#include <iostream>
#define MAX 1000001
using namespace std;

long long arr[MAX];
long long N, M;

long long getLength(long long n) {
    long long sum = 0;
    for(long long i = 1; i <= N; i++) {
        if(arr[i] > n) sum += (arr[i] - n);
    }
    return sum;
}

int main() {
    cin >> N >> M;
    long long max, result = 0;
    for(long long i = 1; i <= N; i++) {
        cin >> arr[i];
        if(arr[i] > max) max = arr[i];
    }

    long long mid;
    long long start = 0, end = max;
    while(start <= end) {
        mid = (start + end) / 2;

        long long sum = getLength(mid);
        
        if(sum >= M) {
            start = mid + 1;
            result = mid;
        }
        else end = mid - 1;
    }
    cout << result;
}