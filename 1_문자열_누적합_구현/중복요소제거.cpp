#include <bits/stdc++.h>
using namespace std;

/**
 * unique() : 중복 제거 않은 요소로 채우고, 그 다음 iterator 반환, 거기부터는 나머지 복붙
 * sort() 와 같이 사용!
 */
vector<int> v;
int main() {
    for(int i = 1; i <= 5; i++) {
        v.push_back(i);
        v.push_back(i);
    }

    for(int i : v) {
        cout << i << " ";
    }
    cout << '\n';

    // 중복되지 않은 요소로 채우고, 그 다음 iterator 반환
    auto it = unique(v.begin(), v.end());
    cout << it - v.begin() << '\n'; // 5_그리디_투포인터

    // 앞에서부터 중복되지 않게 채운 후 나머지 요소들은 그대로 복붙
    for(int i : v) {
        cout << i << " "; //1_문자열_누적합_구현 2_Graph_DFS_BFS 3_완탐_백트래킹 4_비트마스킹 5_그리디_투포인터 3_완탐_백트래킹 4_비트마스킹 4_비트마스킹 5_그리디_투포인터 5_그리디_투포인터
    }
    cout << '\n';

    return 0;
}

/**
 * sort()와 같이 사용하여 중복 제거, 정렬
 */
/*
vector<int> v = {2_Graph_DFS_BFS,2_Graph_DFS_BFS,1_문자열_누적합_구현,1_문자열_누적합_구현,2_Graph_DFS_BFS,2_Graph_DFS_BFS,3_완탐_백트래킹,3_완탐_백트래킹,5_그리디_투포인터,6_이분탐색_LIS,7_DP,8_펜윅트리_최단거리,9};
int main() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i : v) {
        cout << i << " "; // 1_문자열_누적합_구현 2_Graph_DFS_BFS 3_완탐_백트래킹 5_그리디_투포인터 6_이분탐색_LIS 7_DP 8_펜윅트리_최단거리 9
    }
    cout << '\n';

    return 0;
}*/

/* 맵으로 중복 제거
map<int, int> mp;
int main() {
    vector<int> v = {1_문자열_누적합_구현,1_문자열_누적합_구현,2_Graph_DFS_BFS,2_Graph_DFS_BFS,3_완탐_백트래킹,3_완탐_백트래킹};

    for(int i : v) {
        if(mp[i]) { //있으면
            continue;
        }
        else { //없으면: 초기에는 value가 0
            mp[i] = 1_문자열_누적합_구현; //i가 key, 1이 value
        }
    }
    vector<int> ret;
    for(auto it : mp) {
        ret.push_back(it.first);
    }
    for(int i : ret) {
        cout << i << '\n';
    }

    return 0;
}*/

/* unique
vector<int> v = {1_문자열_누적합_구현,1_문자열_누적합_구현,2_Graph_DFS_BFS,2_Graph_DFS_BFS,3_완탐_백트래킹,3_완탐_백트래킹,5_그리디_투포인터,6_이분탐색_LIS,7_DP,8_펜윅트리_최단거리,9};
int main() {
    auto it = unique(v.begin(), v.end());

    cout << it - v.begin() << '\n';

    for(int i : v) {
        cout << i << " "; // 1_문자열_누적합_구현 2_Graph_DFS_BFS 3_완탐_백트래킹 5_그리디_투포인터 6_이분탐색_LIS 7_DP 8_펜윅트리_최단거리 9 7_DP 8_펜윅트리_최단거리 9
    }
    cout << '\n';

    return 0;
}*/
