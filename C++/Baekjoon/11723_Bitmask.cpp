#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string temp= "";
    int M;
    int S = 0;
    cin >> M;

    for(int i = 0; i < M; i++){
        int num;
        cin >> temp;
        
        if(temp == "add"){
            cin >> num;
            S |= (1 << num); //
        }
        else if(temp == "remove"){
            cin >> num;
            S &= ~(1 << num);
        }
        else if(temp == "check"){
            cin >> num;
            if(S & (1 << num)) cout << "1\n";
            else cout << "0\n";
        }
        else if(temp == "toggle"){
            cin >> num;
            if(S & (1 << num)) S &= ~(1 << num);
            else S |= (1 << num);
        }
        else if(temp == "all"){
            S = (1 << 21) - 1;
        }
        else if(temp == "empty"){
            S = 0;
        }
    }
    return 0;
}