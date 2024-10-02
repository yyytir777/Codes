#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

char tel[MAX][11];

struct Trie {
    Trie *node[10];
    bool isEnded;

    Trie() {
        isEnded = 0;
        for(int i = 0; i < 10; i++) {
            node[i] = NULL;
        }
    }

    void insert(char *str) {
        if(*str == '\0') {
            isEnded = 1;
            return;
        }
        
        int num = *str - '0';
        if(node[num] == NULL) node[num] = new Trie();
        node[num]->insert(str+1);
    }

    bool find(char *str) {
        if(*str == '\0') {
            return false;
        }
        
        if(isEnded == true) return true;

        int num = *str - '0';
        if(node[num] == NULL) return false;
        return node[num]->find(str+1);
    }
};

int main() {
    int tc;
    cin >> tc;

    int n;
    while(tc--) {
        cin >> n;

        Trie *root = new Trie();
        for(int i = 0; i < n; i++) {
            cin >> tel[i];
            root->insert(tel[i]);
        }

        for(int i = 0; i < n; i++) {
            if(root->find(tel[i])) {
                cout << "NO\n";
                break;
            }
            if(i == n-1) cout << "YES\n";
        }
    }
}