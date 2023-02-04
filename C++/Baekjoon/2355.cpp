#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long a, b;
    long long result;
    cin >> a >> b;
    if(a > b){
        swap(a, b);
    }
    cout << (a + b) * (b - a + 1) / 2;
    return 0;
}