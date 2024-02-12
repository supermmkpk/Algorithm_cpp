#include <bits/stdc++.h>
using namespace std;

/**
 * 짝짓기, 폭발 => <stack>
 * 무식하게 접근(시간복잡도 고려) -(안되면)-> stack
 */
int a[1000004];
stack<int> stk;
int ret[1000004]; //오큰수 담는 배열


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(ret, -1, sizeof(ret));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { // 인덱스를 이용
        cin >> a[i];

        while (stk.size() && a[stk.top()] < a[i]) { //오큰수 등장 => 확정
            ret[stk.top()] = a[i]; //stk.top()의 오큰수는 a[i] 이다! (확정)
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ret[i] << " ";
    }

    return 0;
}