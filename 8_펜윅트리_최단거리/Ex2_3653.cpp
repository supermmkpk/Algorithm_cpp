#include <bits/stdc++.h>
using namespace std;

/*
 * 1_문자열_누적합_구현) 테스트 케이스의 개수 (<= 100)
 * 2_Graph_DFS_BFS~)  1_문자열_누적합_구현) 가지고 있는 영화의 수 n과 보려고 하는 영화의 수 m (1_문자열_누적합_구현 ≤ n, m ≤ 1e5)
 *      2_Graph_DFS_BFS) 보려는 영화의 번호가 순서대로 주어진다. (1_문자열_누적합_구현 <= <= n)
 * ** 가장 처음에 영화가 쌓여진 순서는 1부터 증가하는 순서이다. 가장 위에 있는 영화의 번호는 1이다.
 * <출력> 각 테스트 케이스에 대해서 한 줄에 m개의 정수를 출력.
 *      i번째 출력하는 수는 i번째로 영화를 볼 때 그 영화의 위에 있었던 DVD의 개수이다. (영화를 볼 때마다 본 영화 DVD를 가장 위에 놓는다.)
 */

/**
 * <펜윅 트리>
 * idx & -idx
 * 누적합처럼 생각
 * 좌표 이동 (idx가 음수일 수 없으니까)
 * 카운팅 트리
 *  void update(int idx, int diff) {
        while(idx <= 최대) {
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
 *  int sum(int idx) {
        int ret = 0;
        while(idx >= 0) {
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
*/

map<int, int> mp;
int tree[200004];

void update(int idx, int diff) {
    while(idx < 200004) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

int sum(int idx) {
    int ret = 0;
    while(idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);



    int t;
    cin >> t;
    while(t--) {
        //초기화
        mp.clear();
        memset(tree, 0, sizeof(tree));

        int n, m;
        cin >> n >> m;
        int move_idx = 100001;
        for(int i = 1; i <= n; i++) {
            update(i + move_idx, 1); //좌표 이동, 영화 등록
            mp[i] = i + move_idx; //좌표 이동
        }
        for(int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;
            int idx = mp[tmp];
            cout << sum(idx) - 1 << " ";
            update(idx, -1); //DVD 빼고
            update(--move_idx, 1); //다 보고 맨 위에 올리기
            mp[tmp] = move_idx; //좌표 갱신
        }
        cout << '\n';
    }

    return 0;
}
