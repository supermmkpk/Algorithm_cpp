#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

/*
 * 20이하의 자연수 N
 */

/**
 * T를 1_문자열_누적합_구현, H를 0으로 생각할 수 있다면... <비트 마스킹>!!
 * 뒤집는 건 ~ 연산.
 * 행에 대해 뒤집고 열은 체크만 해주면 되잖아... : 뒤집은 결과 각 열의 T개수, n - T개수 비교
 */

int a[24]; //모두 0으로 초기화 돼있음.
int n; //n개 행, n개 열
int ret = INF; //최대 -> 최소

void go(int here) {
    if(here == n + 1)  {//행 끝! 열 체크!!, 최소 체크!!, return!
        int sum = 0;
        for(int i = 1; i <= (1 << (n-1)); i *= 2) { //열이니까 : 2_Graph_DFS_BFS^0 ~ 2_Graph_DFS_BFS^(n-1_문자열_누적합_구현)
            int cnt = 0;
            for(int j = 1; j <= n; j++) {
                if(i & a[j]) { //1이면 T => +1_문자열_누적합_구현
                    cnt++;
                }
            }
            sum += min(cnt, n - cnt); //(열 뒤집기 vs 안 뒤집기) 하고 각 열에 대해 반복하며 더하기
        }
        ret = min(sum, ret); //열까지 다 체크 했으니까 최소 체크
        return;
    }
    go(here + 1); //안 뒤집는 경우
    a[here] = ~a[here]; //뒤집기!
    go(here + 1); //뒤집는 경우
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++) {
            if(str[j] == 'T') {//T이면 1로 비트 켜기!
                a[i] |= (1 << j);
            }
        }
    }
    go(1);
    cout << ret << '\n';

    return 0;
}

