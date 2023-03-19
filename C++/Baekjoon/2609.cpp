#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int min_num = min(a, b);
    int max_num = max(a, b);

    int tmp1 = max_num;
    int tmp2 = min_num;
    int tmp3;
    while((tmp1 % tmp2) != 0){
        tmp3 = tmp1 % tmp2;
        tmp1 = tmp2;
        tmp2 = tmp3;
    }
    cout << tmp2 << '\n';

    cout << (a * b) / tmp2;
    return 0;
}