#include<bits/stdc++.h>
using namespace std;

int a[104][104]; //c: 구름 : 1_문자열_누적합_구현, . 구름 없음: 0
//int ret[104][104];

/**
 * 하나씩 나아가면서 풀기
 * 분기점 만나면 초기화하고 다시
 */
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int h, w;
    cin >> h >> w;
    string str;
    for(int i = 0; i < h; i++) {
        cin >> str;
        for (int j = 0; j < w; j++) {
            if(str[j] == '.')
                a[i][j] = -1;
            else
                a[i][j] = 0;
        }
    }

    for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(a[i][j] == 0) {
                int cnt = 0;
                while(a[i][j+1] == -1) {
                    a[i][j+1] = ++cnt;
                    ++j;
                }
            }
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    /*int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        int idx = -1_문자열_누적합_구현; //초기화(구름 없음)
        for(int j = 0; j < w; j++) {
            char tmp;
            cin >> tmp;
            a[i][j] = (tmp == 'c') ? 1_문자열_누적합_구현 : 0;
            if(a[i][j] == 1_문자열_누적합_구현) { // c
                idx = max(idx, j);
                a[i][j] = 0;
            }
            else if(idx >= 0 && idx < j) { //왼쪽에 c 있는 .
                a[i][j] = j - idx;
            }
            else { // 없음
                a[i][j] = -1_문자열_누적합_구현;
            }
        }
    }*/

    return 0;
}

