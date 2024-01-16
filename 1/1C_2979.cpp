#include <bits/stdc++.h>
using namespace std;

/**
 * 카운팅은 맵 또는 배열
 */
int cnt[104];
int A, B, C, t1, t2;
int cost = 0;
int main(void) {
    cin >> A >> B >> C;
    for(int i = 0; i < 3; i++) {
        cin >> t1 >> t2;
        for(int j = t1; j < t2; j++) { //시간대에 트럭 추가
            cnt[j]++;
        }
    }

    for(int i = 1; i < 100; i++) { //각 시간대마다 트럭 대수 체크
        if(cnt[i]) {
            if(cnt[i] == 1)
                cost += A;
            else if(cnt[i] == 2)
                cost += B * 2;
            else if(cnt[i] == 3)
                cost += C * 3;
        }
    }

    cout << cost << '\n';

    return 0;
}