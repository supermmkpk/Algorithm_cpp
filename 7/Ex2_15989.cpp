#include <bits/stdc++.h>
using namespace std;

/*
 * 1) 테스트 케이스의 개수 T
 * 다음 T줄) n (0 < n <= 10,000)
 * <출력> 각 테케마다 1, 2, 3의 합으로 나타내는 방법의 수 (개행)
 * ** 순서만 다른 것은 같은 것으로 한다
 */

/**
 * <DP>
 * 기저 사례, 메모이제이션, 로직, 초기화
*/

int dp[10004]; //초기화(전역변수), 메모이제이션

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp[0] = 1; //기저 사례
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 10000; j++) {
            if(j - i >= 0)
                dp[j] += dp[j - i]; //로직, 메모이제이션
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
