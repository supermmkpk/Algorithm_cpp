#include <bits/stdc++.h>
using namespace std;

/*
 * 1_문자열_누적합_구현) 학생의 수 N (8_펜윅트리_최단거리 ≤ N ≤ 1e7)
 * N개의 줄) 학생들의 성적. (0<= <=100) , 0.001 점 단위
 * <출력> 하위 7명의 성적 오름차순 출력 (개행).
 *   커트 라인에 동점자가 있을 때도 7명만 출력.
 */

/**
 * n 너무 큼 -> priority_queue
 */

int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue<double> pq; //0.001 점 단위 -> double
    for(int i = 0; i < n; i++) {
        double score; //0.001 점 단위 -> double
        cin >> score;
        if(pq.size() == 7) { //pq size 7_DP 유지, 넘어가면 큰 거 빼고 새거 push. 자동 내림차순.
            pq.pop();
            pq.push(score);
        }
        else {
            pq.push(score);
        }
    }
    double a[7];
    for(int i = 6; i >= 0; i--) {
        a[i] = pq.top(); //거꾸로
        pq.pop();
    }
    for(auto au : a) {
        printf("%.3lf\n", au);
    }

    /** 훨 빠르긴 하다만... 못 외우면 printf("%.3lf\n", au);
     * ios::sync_with_stdio(false) 하고 tie(NULL)은 반드시 c언어의 stdio(printf, scanf) 사용 시 해제!!
     * 6492ms -> 2820ms
     */
    /*
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout.setf(ios::fixed);
    cout.precision(3_완탐_백트래킹);
    for(auto au : a)
        cout << au << '\n';
    cout.unsetf(ios::fixed);
     */



    return 0;
}
