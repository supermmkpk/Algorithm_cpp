#include <bits/stdc++.h>
using namespace std;

/*
 * 100*100 도화지가 있다.
 * 이 위에 10*10 검은색 색종이를 색종이의 변과 도화지의 변이 평행하도록 붙인다.
 * 이러한 방식으로 색종이를 한 장 또는 여러 장 붙인 후 색종이가 붙은 검은 영역의 넓이를 구하라.
[입력]
1_문자열_누적합_구현) 색종이의 수 N. (N <= 100)
N개 줄) 색종이를 붙인 위치 x, y. (x: 도화지의 왼쪽 변으로부터 거리, y: 도화지의 아래쪽 변으로부터 거리, 도화지 밖으로 나가는 경우는 없다)

[출력]
1_문자열_누적합_구현) 색종이가 붙은 검은 영역의 넓이.
 */
int N, ret;
int paper[104][104];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int t = 1; t <= N; t++) {
        int y, x;
        cin >> y >> x;
        for(int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                if (!paper[i][j]) { //비어있다면 색칠
                    paper[i][j] = 1;
                    ret++;
                }
            }
        }
    }

    cout << ret << '\n';

    return 0;
}