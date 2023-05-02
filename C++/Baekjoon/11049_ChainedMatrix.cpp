#include <iostream>
using namespace std;

int d[502] = {0,};

int main(){
    int n, r, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> c;
        d[i] = r, d[i+1] = c;
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << d[i] << " ";
    }
    

    return 0;
}