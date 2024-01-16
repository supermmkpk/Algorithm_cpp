#include <bits/stdc++.h>
using namespace std;

/*
 *  ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열
 *  “( )” 은 기본 VPS
 *  x 가 VPS ->  “(x)”도 VPS
 *   두 VPS x 와 y -> x + y도 VPS
 *   <입력> T개 테케, 괄호 문자열의 길이는 2 이상 50 이하
 *   <출력> (VPS)이면 “YES”, 아니면 “NO”
 */

/**
 * 짝짓기, 폭발 => <stack> !!!
 */
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        //초기화
        stack<int> stk;
        string given;
        cin >> given;
        bool no = 0;
        for(int i = 0; i < given.size(); i++) {
            if(given[i] == '(') {
                stk.push(1);
            }
            if(given[i] == ')') {
                if(!stk.empty()) {
                    stk.pop();
                }
                else {
                    no = 1;
                    break;
                }
            }
        }
        if(stk.empty() && no == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}
