#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n == 1){
        return false;
    }

    for(int i = 0; i < n; i++){
        for(int j = 2; j < n; j++){
            if(n % j == 0){ //¼Ò¼öX
                return false;
            }
        }
    }
    return true;
}

int main(){
    int m, n, min_prime;
    int sum = 0;
    cin >> m >> n;

    for(int i = m; i < n; i++){
        if(isPrime(i) == true){
            sum += i;
            min_prime = min(min_prime, i);
        }
    }
    if(sum == 0){
        cout << "-1";
        return 0;
    }
    cout << sum << '\n';
    cout << min_prime;
}