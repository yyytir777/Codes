#include <iostream>
using namespace std;

int main(){
    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        string str;
        cin >> str;
        cout << str[0] << str[str.size() - 1] << '\n';
    }
    return 0;
}