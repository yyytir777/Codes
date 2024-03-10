#include <iostream>
using namespace std;

/**
 * state : fullness & drinkWater
*/

bool dp[5000001][2];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    dp[0][0] = 1;

    int T, A, B;
    cin >> T >> A >> B;

    // 물 마시는 순회
    for (int i = 0; i < T + 1; i++){
        
        if (i - A >= 0)
        //이전 상태에서 업데이트
            dp[i][0] |= dp[i - A][0];

        if (i - B >= 0)
            dp[i][0] |= dp[i - B][0];

        dp[i / 2][1] = dp[i][0];
    }

    //물 마신 후 순회
    for (int i = 0; i < T + 1; i++){
        
        if (i - A >= 0)
            dp[i][1] |= dp[i - A][1];

        if (i - B >= 0)
            dp[i][1] |= dp[i - B][1];
    }

    for (int i = T; i >= 0; i--){
        if (dp[i][1]) {
            cout << i;
            break;
        }
    }

    return 0;
}

/*

    // bfs
    while (!q.empty()) {
        int fullness = q.front().first;
        bool drinkWater = q.front().second;
        q.pop();
        
        max_fullness = max(max_fullness, fullness);

        // A를 먹었을 떄(A를 먹어도 T보다 크지 않을 때 & 방문하지 않았을 때)
        if (fullness + A <= T && !dp[fullness + A][drinkWater]) {
            // 방문 + push
            dp[fullness + A][drinkWater] = 1;
            q.push(make_pair(fullness + A, drinkWater));
        }
        

        // B를 먹었을 때 (B를 먹어도 T보다 크지 않을 때 & 방문하지 않았을 때)
        if (fullness + B <= T && !dp[fullness + B][drinkWater]) {
            // 방문 + pushs
            dp[fullness + B][drinkWater] = 1;
            q.push(make_pair(fullness + B, drinkWater));
        }

        // 물을 마셨을 때
        if (!drinkWater && !dp[fullness/2][!drinkWater]) {
            // 방문 + push (이때 물 마심)
            dp[fullness / 2][1] = 1;
            q.push(make_pair(fullness / 2, 1));
        }
    }

    cout << max_fullness << endl; // max_fullness 출력

*/