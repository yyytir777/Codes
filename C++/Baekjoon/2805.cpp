#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tree;

int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m); //n = 나무의 수, m = 필요한 나무 길이
    for(int i = 0; i < n; i++){
        scanf("%lld", &tree[i]);
    }

    sort(tree.begin(), tree.end());

    long long min, max, mid, sum;

    min = tree[0];
    max = tree[n-1];

    int answer = 0;

    while(min <= max){
        mid = (min + max) / 2;
        sum = 0;

        for(int i = 0; i < n; i++){
            if(tree[i] > mid){
                sum += (tree[i] - mid);
            }
        }

        if(sum >= m){
            answer = mid;
            min = mid + 1;
        }
        else{
            max = mid - 1;
        }
    }
    cout << answer << '\n';

    return 0;
}