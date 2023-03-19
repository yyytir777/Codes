#include <iostream>
using namespace std;

bool arr[21] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        string str;
        int n;

        cin >> str;

        if(str == "add"){
            cin >> n;
            if(arr[n] == false){
                arr[n] = true;
            }
        }

        else if(str == "remove"){
            cin >> n;
            if(arr[n] == true){
                arr[n] = false;
            }
        }

        else if(str == "check"){
            cin >> n;
            if(arr[n] == false){
                cout << "0" << '\n';
            }
            else if(arr[n] == true) {
                cout << "1" << '\n';
            }
        }

        else if(str == "toggle"){
            cin >> n;
            if(arr[n] == 0){
                arr[n] = 1;
            }
            else if(arr[n] == 1){
                arr[n] = 0;
            }
        }

        else if(str == "all"){
            for(int i = 1; i <= 20; i++){
                arr[i] = 1;
            }
        }

        else if(str == "empty"){
            for(int i = 0; i <= 20; i++){
                arr[i] = 0;
            }
        }
    }
    return 0;
}