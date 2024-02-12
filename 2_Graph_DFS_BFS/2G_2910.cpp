#include<bits/stdc++.h>
using namespace std;

/**
 * 커스텀 정렬!
 * 카운팅은 맵 또는 배열!!
 * c 범위 너무 크므로 맵 사용!
 * map의 정렬 : vector 컨테이너로 옮겨서 정렬!
 * map은 자동으로 값 할당됨 (int: 0, string: "")
 */
map<int, int> mp; // counting {값, 빈도}
map<int, int> mp_first; // 누가 먼저? {값, 첫 등장 인덱스}
vector<pair<int, int>> v; // {값, 빈도}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return mp_first[a.first] < mp_first[b.first];
    }
    return a.second > b.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, c, given;
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> given;
        mp[given]++;
        if(mp_first[given] == 0) { //없으면(처음 등장)
            mp_first[given] = i + 1; // 0으로 하면 할당 안 된 것으로 간주
        }
    }

    for(auto it : mp) {
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), cmp);

    for(auto it : v) {
        for(int i = 0; i < it.second; i++) {
            cout << it.first << " ";
        }
    }

    return 0;
}

