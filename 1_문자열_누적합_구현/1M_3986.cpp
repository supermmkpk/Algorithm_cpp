#include <bits/stdc++.h>
using namespace std;

/**
 * <스택>
 * 잘 모르겠으면 뒤집어 보거나, 90도 돌려 보거나, 이어 붙여 보거나...
 * stack.pop() 또는 queue.front() 할 때는 반드시! size() 체크!!
 *  => stack.size() && stack.pop()
 *  짝짓기, 폭발 나오면 : stack 생각하기!!
 */
int n = 0, ret = 0;
string str = "";
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) { //각 테스트 케이스에 대하여
        cin >> str;
        stack<char> stk; //테케마다 스택 초기화!
        for(auto a : str) { //문자열의 각 문자에 대하여
            if(stk.size() && stk.top() == a) { //top()시, 반드시 size check!!
                stk.pop(); //같으면 pop()
            }
            else {
                stk.push(a);
            }
        }
        if(stk.size() == 0) {
            ret++;
        }
    }
    cout << ret << '\n';

    return 0;
}