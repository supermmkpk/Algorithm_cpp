#include <bits/stdc++.h>
using namespace std;


/**
 * <재귀 함수>
 * 재귀함수는 종료조건!!!
 * 반씩 나눠서 변수에 넣고 제곱.
 * modulo 연산(%)은 각각 해야 숫자 범위 안 넘어감
 *  => (a * b) % c  <=>  (a % c) * (b % c)
 *  큰 수를 다루므로 long long
 *  결과적으로 최대 log2 20억 시간에 할 수 있음.
 *  for로 하나하나 다 곱하면 20억.
 */
typedef long long ll;
ll a, b, c, ret;

ll go(ll a, ll b) {
    if(b == 1) { //종료 조건!!
        return a % c;
    }
    ret = go(a, b / 2); //반씩 나눠서 변수에 넣고 제곱
    ret = (ret * ret) % c; //곱하기. %는 각각 곱할 때마다!
    if(b % 2) { //홀수면
        ret = (ret * a) % c; //한 번 더 곱한다!
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    cout << go(a,b) << '\n';

    return 0;
}