#include <bits/stdc++.h>
using namespace std;


/**
 * 상한+1
 * 최소는?
 * 최대: 최소 >>>> 최대
 * 최소: 최대 >>>> 최소
 * 연속 온도 합 : 누적합(구간합)!!
 * 누적합 구할 떄는 1부터!! (i=1 ; i<=n) (i=k ; i<=n)
 */
int n, k;
int psum[100001]; //2~10만 니까 +1
int ret = -10000000, given; //최소는?
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) { //누적합 구할 때는 1부터!!
        cin >> given;
        psum[i] = psum[i-1] + given; //누적합 구하기
    }
    for(int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i - k]); //구간합 중 최대
    }
    cout << ret << '\n';

    return 0;
}