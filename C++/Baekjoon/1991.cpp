#include <iostream>
#include <vector>
#define MAX 26
using namespace std;

struct node{
    char left;
    char right;
};

int N;
node arr[26];

void pre(char cur_node) {
    if(cur_node == '.') return;

    cout << cur_node;
    pre(arr[cur_node - 'A'].left);
    pre(arr[cur_node - 'A'].right);
}

void inOrder(char cur_node) {
    if(cur_node == '.') return;

    inOrder(arr[cur_node - 'A'].left);
    cout << cur_node;
    inOrder(arr[cur_node - 'A'].right);
}

void post(char cur_node) {
    if(cur_node == '.') return;

    post(arr[cur_node - 'A'].left);
    post(arr[cur_node - 'A'].right);
    cout << cur_node;
}


int main() {
    cin >> N;

    char tmp, tmp1, tmp2;
    for(int i = 0; i < N; i++) {
        cin >> tmp >> tmp1 >> tmp2;
        arr[tmp - 'A'].left = tmp1;
        arr[tmp - 'A'].right = tmp2;
    }

    pre('A');
    cout << endl;
    inOrder('A');
    cout << endl;
    post('A');
}