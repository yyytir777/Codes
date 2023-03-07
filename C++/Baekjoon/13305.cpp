#include <iostream>
#include <vector>
using namespace std;

vector<int> road;
vector<int> city;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a;
        cin >> a;
        road.push_back(a);
    }

    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        city.push_back(b);
    }
    
    int min = city[0];
    int cost = 0;
    for(int i = 0; i < n - 1; i++){
        if(min >= city[i]){
            cost += city[i] * road[i];
            min = city[i];
        }
        else{
            cost += city[i-1] * road[i];
        }
    }

    cout << cost << '\n';
    return 0;
}