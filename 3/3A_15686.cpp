#include <bits/stdc++.h>
using namespace std;

/**
 * <조합의 재귀적 구현>
 * 최솟값 담는 변수는 987654321로 초기화!
 */
int n, m; //N(2 ≤ N ≤ 50) , M(1 ≤ M ≤ 13)
vector<vector<int>> openList; // 폐업 시키지 않을 인덱스 리스트
vector<pair<int, int>> home, chicken; // 집, 치킨집 좌표

void combi(int start, vector<int> v) { //모든 치킨집들(chicken.size()) 중 폐업시키지 않을 치킨집 m개 뽑기!
    if(v.size() == m) {
        openList.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                home.push_back({i, j});
            else if(tmp == 2)
                chicken.push_back({i, j});
        }
    }

    vector<int> v;
    combi(-1, v); //C(치킨집, m)
    int ret = 0, result = 987654321;
    for(auto oList : openList) {
        ret = 0;
        for(auto h : home) {
            int mn = 987654321;
            for (auto o: oList) {
                int dist = abs(h.first - chicken[o].first) + abs(h.second - chicken[o].second); //거리
                mn = min(mn, dist); //가장 가까운 거리: 치킨거리 mn
            }
            ret += mn; //치킨 거리의 합 : 도시의 치킨 거리
        }
        result = min(result, ret); //도시의 치킨 거리의 최소 : 답
    }
    cout << result << '\n';

    return 0;
}
