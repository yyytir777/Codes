#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;

bool arr[MAX] = {false,};
int time[MAX] = {0,};
queue<int> q;

int bfs(int v){
    int v_next;
    q.push(v);
    arr[v] = true;

    while(!q.empty()){
        v = q.front();
        q.pop();

        if(v == 1){
            return 0;
        }

        if(v % 3 == 0 && arr[v/3] == false){
            v_next = v / 3;
            arr[v_next] = true;
            time[v_next] = time[v] + 1;
            q.push(v_next);
        }
        else if(v_next == 1){
            return time[v_next];
        }

        
        if(v % 2 == 0 && arr[v/2] == false){
            v_next = v / 2;
            arr[v_next] = true;
            time[v_next] = time[v] + 1;
            q.push(v_next);
        }
        else if(v_next == 1){
            return time[v_next];
        }

        
        if(arr[v - 1] == false){
            v_next = v - 1;
            arr[v_next] = true;
            time[v_next] = time[v] + 1;
            q.push(v_next);

        }
        else if(v_next == 1){
            return time[v_next];
        }
    }
}

int main(){
    int n;
    cin >> n;

    cout << bfs(n);
    return 0;
}