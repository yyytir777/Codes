#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
int max_n[10] = {0,};
int min_n[10] = {0,};

int main(){
    char sign[10];

    int k;
    cin >> k;
    //숫자 개수는 k+1
    for(int i = 0; i < k; i++){
        cin >> sign[i];
    }
    
    for(int i = 0; i < k + 1; i++){
        max_n[i] = 9 - i;
        min_n[i] = i;
    }

    for(int i = 0; i < ){
        string str;
        for(int j = 0; j < k+1; j++){
            str += max_n[i];
        }
        v.push_back(str);
    }

    for(int i = 0; i < k + 1; i++){
        cout << max_n[i] << " " << min_n[i] << endl;
    }

    for()
    return 0;
}