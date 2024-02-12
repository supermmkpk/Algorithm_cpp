#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

/*
 *  식재료의 개수 N (3_완탐_백트래킹<= N <= 15)
 *  최소 영양성분 mp, mf, ms, mv (0~500)
 *  각 N개 줄에 i번(1_문자열_누적합_구현~) 식재료의 영양분 p, f, s, v, 가격 c
 *  <출력> 최소 비용 (\n) 식재료 번호(오름차순)
 *  같은 조합 여러개 : 사전 순 빠른거
 *  조합 없음 : -1_문자열_누적합_구현
 */

/**
 * 가능한 식재료의 모든 조합 => <비트 마스킹>!
 */

struct A { //식재료 객체
    int p, f, s, v,  c;
} a[16];
map<int, vector<vector<int>>> ret_mp; //각 최소비용(key)에 대하여 가능한 조합 벡터(v)들을 저장할 맵 ret_mp

int ret = INF; //최대 -> 최소

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int mp, mf, ms, mv;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++) {
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c; //식재료 i번 객체 a[i]의 영양분, 가격 정보 저장.
    }

    for(int i = 1; i < (1 << n); i++) { //가능한 식재료 번호들의 조합 : 비트 마스킹
        //초기화!! (각 조합마다 갱신하고 체크하는 변수이므로)
        int p1 = 0, f1 = 0, s1 = 0, v1 = 0, cost = 0;
        vector<int> v; //식재료 번호 조합 저장할 벡터 v
        for(int j = 0; j < n; j++) { //각 조합을 매핑 ex) 010011을 식재료 번호에 매핑
            if(i & (1 << j)) { //하나씩 왼쪽으로 전진하면서 1로 매칭이면 매핑
                v.push_back(j + 1); //재료 번호를 push_back
                //이 재료 영양소, 가격 정보 더하기 (갱신)
                p1 += a[j].p;
                f1 += a[j].f;
                s1 += a[j].s;
                v1 += a[j].v;
                cost += a[j].c;
            }
        }
        if(p1 >= mp && f1 >= mf && s1 >= ms && v1 >= mv ) {//이 조합이 조건 통과하면
            if(ret >= cost) {
                //이 조합의 비용이 더 작으면 갱신!
                ret = cost;
                ret_mp[ret].push_back(v); //ret(key)에 조합 벡터 v 푸쉬백.
            }
        }
    } //end of for loop : 모든 조합을 살펴봄!

    if(ret == INF) //갱신 X => 가능한 조합이 없음!
        cout << -1 << '\n';
    else {
        cout << ret << '\n';
        //ret의 최소비용에 해당하는 조합(v)이 여러개이면 사전 순 첫번째 출력
        sort(ret_mp[ret].begin(), ret_mp[ret].end());
        for(auto i : ret_mp[ret][0]) {
            cout << i << " ";
        }
        cout << '\n';
    }

    return 0;
}

