#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    int n;
    cin >> n;

    if(!n) {
        cout << "0";
        return 0;
    }
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    double num = (double)n * 15 / 100;
    int rotate = round(num);

    double sum = 0;
    for(int i = rotate; i < n - rotate; i++) {
        sum += v[i];
    }
    cout << round(sum / (n - rotate * 2));
}   