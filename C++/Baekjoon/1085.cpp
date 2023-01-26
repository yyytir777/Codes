#include <iostream>
using namespace std;

int main(){
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int axis_x, axis_y;
    if((w - x) > x){ //0에 더 가까우면
        axis_x = x;
    }
    else{
        axis_x = w - x;
    }

    if((h - y) > y){
        axis_y = y;
    }
    else{
        axis_y = h - y;
    }

    if(axis_x > axis_y){
        cout << axis_y;
    }
    else{
        cout << axis_x;
    }
    return 0;
}