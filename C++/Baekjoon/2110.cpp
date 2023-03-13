#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int home[200000] = {0,};
int main(){
    int n, c;
    cin >> n >> c; // n = 집 개수, c = 공유기 개수

    for(int i = 0; i < n; i++){
        cin >> home[i];
    }

    sort(home, home + n);

    int min = home[0];
    int max = home[n-1];

    while(min <= max){
        int mid = (min + max) / 2;

        for(int i = 0; i < n; i++){
            
        }
    }
    return 0;
}