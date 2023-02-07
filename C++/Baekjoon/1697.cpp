#include <iostream>
#include <queue>
#define MAX 100002
using namespace std;
//최단경로이므로 BFS 사용

int arr[MAX];
bool check[MAX] = {0,};
int time[MAX] = {0,};
queue<int> q;

int BFS(int v,int k){
    if(v == k){
        return 0;
    }
    int v_next;
    q.push(v);
    check[v] = true;

    while(!q.empty()){
        v = q.front();
        q.pop();
        
        v_next = v - 1;
        if(v_next == k && v_next < MAX && v_next >= 0){
            time[v_next] = time[v] + 1;
            return time[v_next];
        }
        else if(check[v_next] == false && v_next < MAX && v_next >= 0){
            time[v_next] = time[v] + 1;
            check[v_next] = true;
            q.push(v_next);
        }


        v_next = v + 1;
        if(v_next == k && v_next < MAX && v_next >= 0){
            time[v_next] = time[v] + 1;
            return time[v_next];
        }
        else if(check[v_next] == false && v_next < MAX && v_next >= 0){
            time[v_next] = time[v] + 1;
            check[v_next] = true;
            q.push(v_next);
        }


        v_next = v * 2;
        if(v_next == k && v_next < MAX && v_next >= 0){
            time[v_next] = time[v] + 1;
            return time[v_next];
        }
        else if(check[v_next] == false && v_next < MAX && v_next >= 0){
            check[v_next] = true;
            time[v_next] = time[v] + 1;
            q.push(v_next);
        }
    }
    
}

int main(){
    int n, k;
    cin >> n >> k;

    cout << BFS(n, k);
    return 0;
}