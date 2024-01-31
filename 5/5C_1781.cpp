#include <bits/stdc++.h>
using namespace std;

/**
 * BJ1781 [G2] : 컵라면
 * 아이디어: - {데드라인, 컵라면} pair의 vector에 저장하고, 정렬(데드라인 기준 오름차순)
 *          - priority_queue의 size와 데드라인 비교해서 최소 컵라면 수를 빼 버리기
 *          ** 최대: 최소가 적다. or 최대가 많다.
 * 결과: 6244KB, 56ms
 */

/*
 * 동호가 받을 수 있는 최대 컵라면 수를 구하라.
 * 문제를 푸는데는 단위 시간 1이 걸리며, 각 문제의 데드라인은 N이하의 자연수이다.
[입력]
1) 숙제의 개수 N. (1 ≤ N ≤ 200,000)이 들어온다.
N개 줄) 문제에 대한 데드라인 <공백> 받을 수 있는 컵라면 수 (1<= 컵라면수 <= 230)

[출력]
받을 수 있는 최대 컵라면 수
*/
int N; //숙제 개수 N
vector<pair<int, int>> v; //{데드라인, 컵라면} pair 벡터
priority_queue<int, vector<int>, greater<int>> pq; //기본: 내림차순 -> greater<int>: 오름차순
int ret = 0; //결과: 최대 컵라면 수

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //숙제 개수 N 입력
    cin >> N;

    //데드라인, 컵라면 수 입력
    for(int i = 0; i < N; i++) {
        int deadLine, cup;
        cin >> deadLine >> cup;
        v.push_back({deadLine, cup});
    }

    //데드라인 기준 정렬(pair의 기본 정렬)
    sort(v.begin(), v.end());

    //priority_queue의 size와 데드라인 비교, 갱신(데드라인이 size를 벗어나면 최소를 빼 버린다)
    ret = 0;
    for(auto eachV : v) {
        ret += eachV.second;
        pq.push(eachV.second);
        if(pq.size() > eachV.first) {
            ret -= pq.top(); //최소 빼 버리기
            pq.pop();
        }
    }
    cout << ret <<'\n'; //출력

    return 0;
}
