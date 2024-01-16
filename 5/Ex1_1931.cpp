#include <bits/stdc++.h>
using namespace std;

/*
 *
 * 회의의 시작시간과 끝나는 시간이 같을 수도 있다
 * 회의의 수 N(1 ≤ N ≤ 100,000)
 * 시작시간 (공백) 끝나는 시간
 * <출력> 겹치지 않게 회의의 최대 개수
 */

/**
 * 정렬에 의해 최적해를 찾는다. <그리디>
 * 끝 시간 순으로 정렬! -> 교차 지점 처리.
 * pair는 first->second 순 정렬이므로, from, to 바꿔서 넣어서 정렬하기. 즉, to 기준 우선 정렬하기
 */

vector<pair<int, int>> v;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        v.push_back({to, from}); //끝 시간 순 정렬해야 하니까 반대로!
    }
    sort(v.begin(), v.end());

    int to = v[0].first;
    int ret = 1;
    for(int i = 1; i < v.size(); i++) {
        //au.first는 끝 시간, au.second는 시작 시간
        if(v[i].second < to) //시작이 전꺼 끝보다 빠름 : 아님! -> continue;
            continue;
        to = v[i].first; //시작이 전꺼 끝 이후 : 맞음! -> ++ret;
        ++ret;
    }
    cout << ret << '\n';

    return 0;
}
