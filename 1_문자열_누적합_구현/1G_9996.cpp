#include <bits/stdc++.h>
using namespace std;


/**
 * find() : 그 인덱스 반환
 * substr(begin, length): begin부터 길이만큼 자른다.
 * 반례 생각하기!!
 */
int n = 0, pos = 0;
string pre, suf, str, given;
int main(void) {
    cin >> n;
    cin >> given;
    pos = given.find("*");
    pre = given.substr(0, pos);
    suf = given.substr(pos + 1);
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(pre.size() + suf.size() > str.size()) { //반례: ab*ab에 대하여 ab
            cout << "NE\n";
        }
        else { //앞 뒤만 같으면 된다!
            if (str.substr(0, pos) == pre &&
                str.substr(str.size() - suf.size()) == suf) {
                cout << "DA\n";
            }
            else {
                cout << "NE\n";
            }
        }
    }


    return 0;
}