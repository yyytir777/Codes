#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= 250; i++){
        if(i * 4 <= n && n < (i + 1) * 4){
            for(int j = 0; j < i; j++){
                cout << "long ";
            }
            cout << "int";
        }
    }

    return 0;
}