#include<bits/stdc++.h>
using namespace std;

bool vowel(char a) { // 모음이냐?
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

/**
     * for(처음에 할 거; 중단 조건; 끝날때마다 올라오면서 할 것)
     * 몇 개 연속: cnt++ 이용. 연속이 끝나면 cnt=0
*/
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    string str;
    for(cin >> str; str != "end"; cin >> str) {
        //초기화!!
        int vcnt = 0, ccnt = 0; //vcnt:모음, ccnt:자음
        bool hasVowel = false;
        bool ret = true;

        for(int i = 0; i < str.length(); i++) {
            if(vowel(str[i])) {
                hasVowel = true;
                vcnt++;
                ccnt = 0;
            }
            else {
                ccnt++;
                vcnt = 0;
            }
            if(vcnt >= 3 || ccnt >= 3) {
                ret = false;
                break;
            }
            if(i >= 1 && str[i] == str[i-1]) {
                if(str[i] == 'e' || str[i] == 'o')
                    continue;
                else {
                    ret = false;
                    break;
                }
            }
        }
        if(hasVowel == false) {
            ret = false;
        }

        if(ret)
            cout << "<" << str << ">" << " is acceptable." << '\n';
        else
            cout << "<" << str << ">" << " is not acceptable." << '\n';
    }

    return 0;
}
