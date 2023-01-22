#include <iostream>
using namespace std;

int main(){
    int arr[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
    int time = 0;
    string alphabet;

    cin >> alphabet;

    for(int i = 0; i < alphabet.size(); i++){
        int t = int(alphabet[i]) % 65;
        time += arr[t];
    }
    cout << time;
    return 0;
}