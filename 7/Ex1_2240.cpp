#include <bits/stdc++.h>
using namespace std;

/*
 * 자두는 T(1≤T≤1,000)초 동안 떨어지게 된다. 자두는 최대 W(1≤W≤30)번만 움직이고 싶어 한다.
 * 자두는 1번 자두나무 아래에 위치해 있다고 한다.
 * 1) T, W (1 ≤ T ≤ 1000), (1 ≤ W ≤ 30)
 * T개 줄) 매 초마다 자두가 떨어지는 나무의 번호 (1 또는 2)
 * <출력> 받을 수 있는 자두의 최대 개수
 */

/**
 * <DP>
 * 완탐? : 1or2 30번까지 이동 가능 -> 2^30 경우의 수. => 너무 큼 => 메모이제이션 가능! => DP!
 * 기저 사례, 메모이제이션, 로직, 초기화
*/

int namuNum[1004]; //i초에 자두가 떨어지는 나무 번호
int dp[1004][2][34];
int t, w;

int go(int time, int treeNum, int moveLeft) {
    ///기저 사례
    if(moveLeft < 0) {
        return -1e9;
    }
    if(time == t) {
        if(moveLeft == 0) //많이 움직여야 자두를 최대로 먹을 수 있지 않을까?
            return 0;
        else
            return -1e9;
    }
    ///메모이제이션
    int &ret = dp[time][treeNum][moveLeft];
    if(ret != -1) //if(~ret) //최적 부분 해 있으면 반환
        return ret;
    else { //없으면 만들기
        ///로직
        //이동하거나, 안하거나. 자두 떨어지는 나무면 먹어서 + 1 (true = 1, false = 0)
        return ret = max(go(time + 1, treeNum^1, moveLeft - 1), go(time + 1, treeNum, moveLeft)) + (treeNum == namuNum[time] - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t >> w; //t초 동안, w번까지 이동 가능
    for(int i = 0; i < t; i++) {
        cin >> namuNum[i]; //1 or 2
    }

    ///초기화
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, w) << '\n';

    return 0;
}

