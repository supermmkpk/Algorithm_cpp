#include <bits/stdc++.h>
using namespace std;
#define prev aaaa
#define MAX 200004
/*
 * 선거구는 구역을 적어도 하나 포함해야 하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다
 * 1_문자열_누적합_구현) 구역의 개수 N (2_Graph_DFS_BFS ≤ N ≤ 10)
 * 2_Graph_DFS_BFS) 구역의 인구가 1번 구역부터 N번 구역까지 순서대로 주어진다. (공백 구분) (1_문자열_누적합_구현 ≤ 인구 수 ≤ 100)
 * N개 줄) 각 구역과 인접한 구역의 정보가 주어진다. 각 정보의 첫 번째 정수는 그 구역과 인접한 구역의 수이고, 이후 인접한 구역의 번호가 주어진다.
 * 구역 A가 구역 B와 인접하면 구역 B도 구역 A와 인접하다. 인접한 구역이 없을 수도 있다.
 * <출력> 백준시를 두 선거구로 나누었을 때, 두 선거구의 인구 차이의 최솟값. 나눌 수 없는 경우에는 -1_문자열_누적합_구현
 */

/**
 * <Connected Component> => <DFS>
 * 연결해보자!
 */

int n;
int people[14];
vector<int> adj[14];
int visited[14];
int comp[14];

pair<int, int> DFS(int now, int value) {
    pair<int, int> ret = {1, people[now]};
    visited[now] = 1;
    for(auto next : adj[now]) {
        if(visited[next] == 0 && comp[next] == value) {
            pair<int, int> tmp = DFS(next, value);
            ret.first += tmp.first; //정점 수
            ret.second += tmp.second;
        }
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) { //정점 1_문자열_누적합_구현~n 까지의 인구 수
        cin >> people[i];
    }
    //N개 줄) 각 구역과 인접한 구역의 정보가 주어진다. 각 정보의 첫 번째 정수는 그 구역과 인접한 구역의 수이고, 이후 인접한 구역의 번호가 주어진다.
    for(int i = 1; i <= n; i++) {
        int tmpN;
        cin >> tmpN;
        for(int j = 0; j < tmpN; j++) {
            int tmp;
            cin >> tmp;
            adj[i].push_back(tmp);
        }
    }

    int ret = 1e9;
    for(int i = 1; i < (1 << n) - 1; i++) {
        int idx1 = -1, idx2 = -1;
        memset(comp, 0, sizeof(comp));
        memset(visited, 0, sizeof(visited));

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) { //red:0, blue: 1_문자열_누적합_구현,
                comp[j + 1] = 1; idx1 = j + 1; //blue라면 1_문자열_누적합_구현, 마지막 블루 = idx1
            }
            else {
                idx2 = j + 1; //마지막 레드 = idx2
            }
        }

        pair<int, int> comp1 =  DFS(idx1, 1);
        pair<int, int> comp2 = DFS(idx2, 0);
        if(comp1.first + comp2.first == n) {
            ret = min(ret, abs(comp1.second - comp2.second));
        }
    }
    if(ret == 1e9) {
        cout << -1 << '\n';
    }
    else {
        cout << ret << '\n';
    }

    return 0;
}

