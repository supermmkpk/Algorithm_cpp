#include <bits/stdc++.h>
using namespace std;

/*
 * 1) 보석이 N개, 가방 K개 (1 ≤ N, K ≤ 300,000)
 * N개 줄) 무게 Mi, 가격 Vi (0 ≤ Mi, Vi ≤ 1e6)
 * K개 줄) 가방에 담을 수 있는 최대 무게 Ci (1 ≤ Ci ≤ 1e8)
 * 모든 숫자는 양의 정수이다.
 * 가방에는 최대 한 개의 보석만 넣을 수 있다.
 * <출력> 가능한 보석 가격의 합의 최댓값
 */

/**
 * <그리디>
 * 무게 적게 담을 수 있는 가방 기준
 * 일단 넣어!
 * 작은 가방에 들어가면 그 다음 큰 가방에도 당연히! 들어가겠지.
 * priority_queue는 기본적으로 자동 내림차순
 */

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> bosukV; //무게 Mi, 가격 Vi (0 ≤ Mi, Vi ≤ 1e6)
    vector<int> bagV; //가방에 담을 수 있는 최대 무게 Ci (1 ≤ Ci ≤ 1e8)
    for(int i = 0; i < n; i++) {
        int m, v;
        cin >> m >> v;
        bosukV.push_back({m, v});
    }
    for(int i = 0; i < k; i++) {
        int c;
        cin >> c;
        bagV.push_back(c);
    }

    //정렬!!
    sort(bosukV.begin(), bosukV.end());
    sort(bagV.begin(), bagV.end());

    priority_queue<int> pq;
    int j = 0;
    long long ret = 0; //딴 거는 1e9이하니까 int OK. 얘는 ~1e6짜리를 더하는 놈이니까 long long!!!
    for(int i = 0; i < k; i++) { //작은 가방부터 각 가방에 대하여
        //보석들에 대하여 가방에 들어가냐? -> 들어가면 pq에 가격 넣기. (pq는 기본으로 자동 내림차순)
        for(; j < n && bosukV[j].first <= bagV[i]; j++) {
            pq.push(bosukV[j].second);
        }
        if(pq.size()) {
            ret += pq.top(); //각 가방에 하나만 넣을 수 있으니까 제일 큰 거! (pq는 기본으로 자동 내림차순) => top이 최댓값
            pq.pop();
        }
    }
    cout << ret << '\n';

    return 0;
}
