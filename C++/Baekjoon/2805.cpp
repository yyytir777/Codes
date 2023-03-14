#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> tree;

int main(){
    long long n, m;
    cin >> n >> m; //n = 나무의 수, m = 필요한 나무 길이
    for(long long i = 0; i < n; i++){
        cin >> tree[i];
    }
    
    sort(tree.begin(), tree.end());

    long long min, max, mid, sum;

    min = 0;
    max = tree[n-1];

    int answer = 0;

    while(min <= max){
        mid = (min + max) / 2;
        sum = 0;

        for(long long i = 0; i < n; i++){
            if(tree[i] > mid){
                sum += (tree[i] - mid);
            }
        }
        if(sum >= m){
            max = mid - 1;
        }
        else{
            answer = mid;
            min = mid + 1;
        }
    }
    cout << mid << '\n';
    return 0;
}