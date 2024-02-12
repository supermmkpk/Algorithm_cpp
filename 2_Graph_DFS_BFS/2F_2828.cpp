#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, j; //n칸 스크린, m칸 바구니, j개 사과
    cin >> n >> m >> j; // m,n: [1_문자열_누적합_구현,10], j: [1_문자열_누적합_구현,20]

    int l = 1, r = 1; //바구니의 왼쪽, 오른쪽 위치 정의
    int ret = 0;
    while(j--) {
        int tmp; //사과 떨어지는 위치
        int move; //이동 거리
        cin >> tmp;
        r = l + m - 1;
        if(l <= tmp && tmp <= r ) { //바구니 사이
            continue; //ret 그대로(이동 X)
        }
        else if(tmp < l) {//바구니 왼쪽
            move = l - tmp;
            l -= move; // l = tmp;
            ret += move;
        }
        else if(tmp > r) { //바구니 오른쪽
            move = tmp - r;
            l += move;
            ret += move;
        }
    }
    cout << ret << '\n';

    return 0;
}