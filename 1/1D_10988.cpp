#include <bits/stdc++.h>
using namespace std;

string str, temp;
/**
 * reverse(begin, end) : 원본 배열 수정하며 순서 거꾸로
 * 따라서 임시 배열 temp 사용!
 */
int main(void) {
    cin >> str;
    temp = str;
    reverse(temp.begin(), temp.end());
    if(str == temp) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}