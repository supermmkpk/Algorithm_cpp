#include <bits/stdc++.h>
using namespace std;

/*
 * 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝
 * 대괄호("[")는 오른쪽 대괄호("]")와만 짝
 * <입력> 마지막 글자를 제외하고 영문 알파벳, 공백, 소괄호("( )"), 대괄호("[ ]")
 *   (".")으로 끝나고, 길이는 100글자보다 작거나 같다.
 * <출력> 균형을 이루고 있으면 "yes"를, 아니면 "no"
 */

/**
 * 짝짓기 => <stack>!!
 * 맞는 거만 생각 X -> 틀린 거 기준
 */
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true) {
        string given;
        getline(cin, given);
        if(given == ".")
            break;
        //초기화
        stack<char> stk;
        bool no = 0;
        for(auto g : given) {
            if(g == '(') {
                stk.push(g);
            }
            else if(g == ')') {
                if(stk.empty() || stk.top() == '[') { /// 왼쪽부터. 이미 true면 더이상 오른쪽으로 진행 X
                    no = 1;
                    break;
                }
                else {
                    stk.pop();
                }
            }
            else if(g == '[') {
                stk.push(g);
            }
            else if(g == ']') {
                if(stk.empty() || stk.top() == '(') {
                    no = 1;
                    break;
                }
                else {
                    stk.pop();
                }
            }
            switch(g) {
                case '(':
                    stk.push(g);
                    break;
                case ')':
                    if(!stk.empty() && stk.top() == '(') { //짝이 맞아야!
                        stk.pop();
                    }
                    else {
                        no = 1;
                        break;
                    }
                    break;
                case '[':
                    stk.push(g);
                    break;
                case ']':
                    if(!stk.empty() && stk.top() == '[') { //짝이 맞아야!
                        stk.pop();
                    }
                    else {
                        no = 1;
                        break;
                    }
                    break;
                default:
                    continue;
            }
        }

        if(stk.empty() && no == 0)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;

}

/*
while(true) {
        string given;
        getline(cin, given);
        if(given == ".")
            break;
        //초기화
        stack<char> stk;
        bool no = 0;
        for(auto g : given) {
            if(g == '(') {
                stk.push(g);
            }
            else if(g == ')') {
                if(!stk.empty() && stk.top() == '(') { //짝이 맞아야!
                    stk.pop();
                }
                else {
                    no = 1_문자열_누적합_구현;
                    break;
                }
            }
            else if(g == '[') {
                stk.push(g);
            }
            else if(g == ']') {
                if(!stk.empty() && stk.top() == '[') { //짝이 맞아야!
                    stk.pop();
                }
                else {
                    no = 1_문자열_누적합_구현;
                    break;
                }
            }
        }

        if(stk.empty() && no == 0)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
 */
