#include <iostream>
#include <algorithm>
using namespace std;

int country_cnt[10000];

int main(){
    long long n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> country_cnt[i];
    }

    long long m;
    cin >> m;

    sort(country_cnt, country_cnt + n);

    long long min = 0;
    long long max = country_cnt[n-1];
    long long answer;

    while(min <= max){
        long long upper_limit = (min + max) / 2;

        int sum = 0;
        for(int i = 0; i < n; i++){
            if(country_cnt[i] > upper_limit){
                sum += upper_limit;
            }
            else{//country_cnt[i] <= upper_limit
                sum += country_cnt[i];
            }
        }
        
        if(sum > m){
            max = upper_limit - 1;
        }
        else{
            answer = upper_limit;
            min = upper_limit + 1;
        }
    }
    cout << answer << '\n';
    return 0;
}