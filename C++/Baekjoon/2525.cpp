#include <iostream>
using namespace std;

int main(){
    int h, m, t;
    cin >> h >> m >> t;

    int min = 60 * h + m + t;

    h = (min / 60) % 24;
    m = min % 60;

    cout << h << " " << m;
    return 0;
}