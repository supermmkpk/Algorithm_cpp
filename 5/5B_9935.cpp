#include <bits/stdc++.h>
using namespace std;

/*
 * 폭발 문자열을 포함하고 있는 경우, 모든 폭발 문자열이 사라지게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
 * 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
 * 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
 * 폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.
 * <입력>
 * 1) 문자열 (1<= 길이 <= 1e6)
 * 2) 폭발 문자열 (1<= 길이 <= 36)
 * 문자열 모두 알파벳 소문자와 대문자, 숫자 0~9로만 이루어져 있다.
 * <출력> 폭발이 끝난 후 남은 문자열 (남아있는 문자가 없는 경우, "FRULA")
 */

/**
 * 1) 무식하게 이중 for문 : 100만 * 100만 : 너무 큼!
 * 2) for문 하나로 : 뒤에서 폭발문자열 만큼 확인하고 제거하기!
 * string.substr(시작 idx, 부분문자열 길이) : idx(pos)니까 .size() 사용
 * string.erase(시작 iter, 끝 iter) : [시작, 끝) : iter니까 .end() 사용
 */

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string given, explode;
    cin >> given >> explode;

    string ret = "";
    for(char c : given) { //주어진 문자열의 각 문자에 대하여
        ret += c; //하나씩 추가하면서 확인
        if(ret.size() >= explode.size() && ret.substr(ret.size() - explode.size(), explode.size()) == explode) {
            ret.erase(ret.end() - explode.size(), ret.end()); //iterator
        }
    }
    if(ret.empty())
        cout << "FRULA" << '\n';
    else
        cout << ret << '\n';

    return 0;
}
