#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v1;
vector<string> v2;

int main(){
    int N, M;
    cin >> N >> M;

    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        v1.push_back(temp);
    }

    sort(v1.begin(), v1.end());


    for(int i = 0; i < M; i++) {
        cin >> temp;

        if(binary_search(v1.begin(), v1.end(), temp)) {
            v2.push_back(temp);
        }
    }

    sort(v2.begin(), v2.end());

    cout << v2.size() << endl;

    for(auto tmp : v2) {
        cout << tmp << endl;
    }

    return 0;
}