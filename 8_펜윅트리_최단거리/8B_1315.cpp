#include <bits/stdc++.h>
using namespace std;

/*
 * 2가지 스탯. 힘(STR), 지력(INT)
 * 캐릭터를 생성했을 때, 두 스탯은 모두 1_문자열_누적합_구현
 * N개의 퀘스트 중 i번째 퀘스트를 깨려면 (힘 >= STR[i] || 지력 >= INT[i])
 * 깨면, 스탯 올릴 수 있는 포인트를 PNT[i]개 얻게 된다.(포인트로 마음대로 스탯을 올릴 수 있다.)
 * 모든 퀘스트는 단 한 번만 깰 수 있으며, 퀘스트를 깨는 순서는 마음대로.
 * 깰 수 있는 퀘스트 개수의 최댓값?
 *
 * 1_문자열_누적합_구현) 퀘스트의 개수 N (1_문자열_누적합_구현 <= N <= 50)
 * N개 줄) STR[i], INT[i], PNT[i] (1_문자열_누적합_구현 <= 모두 <= 1_문자열_누적합_구현,000)
 * <출력> 깰 수 있는 퀘스트 개수의 최댓값
 */

/**
 * <DP>
 * 기저사례, 메모이제이션, 로직, 초기화
 */

struct stat {
    int S, I, P;
};
vector<stat> statV;
int dp[1004][1004];
bool visited[54];
int n;

int quest(int STR, int INT) {
    //메모이제이션
    int &ret = dp[STR][INT];
    if(ret != -1) //이미 있으면
        return ret;

    //로직
    ret = 0;
    int pnt = 0;
    vector<int> v; //성공한 퀘스트
    for(int i = 0; i < n; i++) { //n개 퀘스트에 대하여
        if(STR >= statV[i].S || INT >= statV[i].I) { //퀘스트 성공!
            ++ret;
            if(visited[i] == 0) {
                visited[i] = true;
                v.push_back(i);
                pnt += statV[i].P;
            }
        }
    }
    //기저사례: 1000, 로직
    for(int p = 0; p <= pnt; p++) {
        int nextSTR = min(1000, STR + p);
        int nextINT = min(1000, INT + (pnt - p));
        ret = max(ret, quest(nextSTR, nextINT));
    }

    //원복 : 경우의 수들이 오염되는 거 방지!
    for(auto eachV : v) {
        visited[eachV] = false;
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmpS, tmpI, tmpP;
        cin >> tmpS >> tmpI >> tmpP;
        statV.push_back({tmpS, tmpI, tmpP});
    }

    //초기화
    memset(dp, -1, sizeof(dp));
    cout << quest(1,1) << '\n'; //처음 생성 시 스탯 모두 1_문자열_누적합_구현

    return 0;
}
