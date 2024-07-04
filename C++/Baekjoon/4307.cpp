#include <bits/stdc++.h>
using namespace std;

vector<int> min_v;
vector<int> max_v;

bool compare(int a, int b) {
    if(a > b) return true;
    return false;
}
int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        min_v.clear();
        max_v.clear();
        int l, n;
        cin >> l >> n;

        int pos1, pos2;
        for(int i = 0; i < n; i++) {
            cin >> pos1;

            pos2 = abs(l - pos1);
            
            if(pos1 < pos2) {
                min_v.push_back(pos1);
                max_v.push_back(pos2);
            }
            else {
                min_v.push_back(pos2);
                max_v.push_back(pos1);
            }
        }
        // min_v : 2, 4, 3
        // max_v : 8, 6, 7
        sort(min_v.begin(), min_v.end(), compare);
        sort(max_v.begin(), max_v.end(), compare);

        printf("%d %d\n", min_v[0], max_v[0]);
    }
}