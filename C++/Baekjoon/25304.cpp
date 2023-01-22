#include <iostream>
using namespace std;

int main(){
    int total_price;
    int sum = 0;
    cin >> total_price;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        int price, m;
        cin >> price >> m;

        sum += price * m;
    }

    if(sum == total_price){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}