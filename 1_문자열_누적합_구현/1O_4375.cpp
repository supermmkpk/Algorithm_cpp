#include <bits/stdc++.h>
using namespace std;


/**
 * 다 하고 하면 시간 초과 나니까
 * modulo 연산(%)은 과정에서 각각!
 */
int n;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(cin >> n) {
        int ret = 1, cnt = 1;
        while(1) {
            if(cnt % n == 0) {
                cout << ret << '\n';
                break;
            }
            else {
                cnt = cnt * 10 + 1;
                ret++; //자리수 증가
                cnt %= n; //과정에서 % (다 하고 하면 시간초과)
            }
        }
    }

    return 0;
}