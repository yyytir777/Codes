#include<iostream>
#define r 31
#define M 1234567891
using namespace std;

int main() {
    int l;
    cin >> l;

    string temp;
    cin >> temp;

    long long w = 1;
    long long sum = 0;
    for(int i = 0; i < l; i++) {
        sum = (sum + (int(temp[i]) - 96) * w) % M;
        w = (w * r) % M;
    }

    cout << sum;
}