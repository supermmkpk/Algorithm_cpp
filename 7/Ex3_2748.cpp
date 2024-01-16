#include <bits/stdc++.h>
using namespace std;

/*
 * Fn = Fn-1 + Fn-2  where n ≥ 2, F0 = 0, F1 = 1
 * 1) n (1 <= n <= 90)
 * <출력> n번째 피보나치 수.
 */

/**
 * <Top-Down Approach : 재귀>
 * <동적계획법, DP> "재활용"
 * DP : 기저사례, 메모이제이션, 로직, 초기화
*/

typedef long long ll;
ll dp[94]; ///초기화 (전역변수 : 0), 1 <= n <= 90

ll F(int n) {
    ///기저 사례
    if(n == 0) // F0 = 0,
        return 0;
    else if(n == 1) // F1 = 1
        return 1;
    else { // n ≥ 2 : Fn = Fn-1 + Fn-2
        ///메모이제이션
        ll &ret = dp[n];
        if(ret)
            return ret; //이미 있으면 "재활용"
        ///로직
        return ret = F(n-1) + F(n-2); //없으면 만들기
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cout << F(n) << '\n';

    return 0;
}
