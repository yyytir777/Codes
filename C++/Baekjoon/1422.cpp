#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> q;

bool compare(int a, int b){
    return a > b;
}

int main(){
    int k, n;
    cin >> k >> n;

    for(int i = 0; i < k; i++){
        int num;
        cin >> num;
        q.push_back(num);
    }

    sort(q.begin(), q.end(), compare);

    

    return 0;
}