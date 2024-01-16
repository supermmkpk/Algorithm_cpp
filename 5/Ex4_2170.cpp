#include <bits/stdc++.h>
using namespace std;

/*
 * 1) 선을 그은 횟수 N (1 ≤ N ≤ 1,000,000)
 * 다음 N개의 줄) 시점, 종점 x, y (-1,000,000,000 ≤ x < y ≤ 1,000,000,000)
 * <출력> 선의 총 길이
 */

/**
 * <라인 스위핑>
 */

pair<int, int> line[1000004]; //선의 시점(left), 종점(right)를 pair로 저장한다. 그 후 sort! : 시점 -> 종점 순 정렬
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        line[i] = {left, right};
    }

    sort(line, line + n); // n개 선에 대하여 (시점,종점) 정렬

    int left = line[0].first;
    int right = line[0].second;
    int ret = 0;
    for(int i = 1; i < n; i++) { // n개 선에 대하여(첫 번째 제외)  종점, 다음 시점 체크!(겹치는지...)
        if(right < line[i].first) { //right < 다음 left : 지금까지 길이 추가, 시점/종점 갱신
            ret += (right - left);
            left = line[i].first;
            right = line[i].second;
        }
        else if(line[i].first <= right && right <= line[i].second) { //겹치거나 이어지면 종점 업데이트. 그러니까 종점만 보겠다!
            right = line[i].second;
        }
    }
    ret += (right - left); //마지막 꺼 더하기
    cout << ret << '\n';

    return 0;
}
