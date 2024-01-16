#include <bits/stdc++.h>
using namespace std;

/*
 * n개의 대학에서 강연 요청
 * d일 "안에" 와서 강연을 해 주면 p원의 강연료를 지불
 * 하루에 한 곳에서만 강연
 * <입력>
 * 1) n (0 ≤ n ≤ 10,000)
 * n개 줄) p, d (1 ≤ p ≤ 10,000) (1 ≤ d ≤ 10,000)
 * <출력> 최대로 벌 수 있는 돈
 */

/**
 * <그리디>
 * 그리디는 sort or PQ or 둘다!
 * 최대는 최소를 없애거나, 최대를 최대화한다!
 * 앞에 작은 거(최소) 없애면서(d 알 바 아님) d일 == pq.size() 유지!
 * priority_queue의 오름차순 : greater<>
 *   Ex) priority_queue<int, vector<int>, greater<int>> pq;
 */

priority_queue<int, vector<int>, greater<>> pq; //오름차순 PQ 생성! (작은 게 pq.top(), pq.pop())
vector<pair<int, int>> v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; //0 ≤ n ≤ 10,000
    cin >> n;
    for(int i = 0; i < n; i++) {
        int pay, day; //1 ≤ pay ≤ 10,000 , 1 ≤ day ≤ 10,000
        cin >> pay >> day;
        v.push_back({day, pay}); //day 기준 정렬. day -> pay
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) { //n개 요청에 대하여
        pq.push(v[i].second);
        if(pq.size() > v[i].first) { //앞에 작은 거(최소) 없애면서(d 알 바 아님) d일 == pq.size() 유지!
            pq.pop();
        }
    }
    int ret = 0;
    while(!pq.empty()) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << '\n';

    return 0;
}
