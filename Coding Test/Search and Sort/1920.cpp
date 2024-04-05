#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

int arr_m[MAX];

int main() {

    ios
    vector<int> vector_n;
    int n;
    cin >> n;

    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        vector_n.push_back(tmp);
    }

    // ??
    sort(vector_n.begin(), vector_n.end());

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> arr_m[i];
    }
    for(int i = 0; i < m; i++){
        bool exist = binary_search(vector_n.begin(), vector_n.end(), arr_m[i]);

        if(exist) cout << 1 << endl;
        else cout << 0 << endl;
        
    }

    return 0;
}