#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <string> v;

    for(int i = 0; i < 5; i++){
        v.push_back("asdf");
    }


    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}