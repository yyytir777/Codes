#include <iostream>
#include <functional>
using namespace std;


int main(){
    int year;
    cin >> year;

    bool check;

    if (year % 400 == 0) check = true;
    else if (year % 100 == 0) check = false;
    else if (year % 4 == 0) check = true;
    else check = false;

    cout << check << '\n';
    return 0;
}


