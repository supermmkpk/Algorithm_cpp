#include <bits/stdc++.h>
using namespace std;

/*
 * 종말 수: 6이 적어도 3개 이상 연속
 * 입력: n
 * 출력: n 번쩨 종말 수
*/
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //종말 수의 최소 = 666
    int n;
    cin >> n;

    /**
     * 최소인 666에서 1씩 더해가면서 종말 수 확인
     * 찾을 때마다 --n;
     * n == 0 되면 k는 n번째 종말 수.
     */

    int k = 666;//k : 종말 수
    ///k++은 올라오면서 하기 때문에 틀림. 즉, n==0일 때 정답+1이 됨.
    //for(k  = 666; n > 0; k++)
    do {
        if(to_string(k).find("666") != string::npos)
            --n;
        if(n)
            ++k;
    } while(n);
    cout << k << '\n';

    return 0;
}
    /*
    while(n) {
        if(to_string(k).find("666") != string::npos)
            --n;
        if(n)
            ++k;
    }
    for(k = 666; ; k++) {
        if(to_string(k).find("666") != string::npos)
            --n;
        if(n == 0)
            break;
    }
     */
