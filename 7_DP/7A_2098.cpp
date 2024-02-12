#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

/*
 * 1_문자열_누적합_구현~N번 도시들이 있고, 도시들 사이에는 길이 있다. (길이 없을 수도 있다)
 * 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로를 계획
 * 단, 한 번 갔던 도시로는 다시 갈 수 없다 (마지막에 출발했던 도시로 돌아오는 것은 예외)
 * W[i][j]는 도시 i에서 도시 j로 가기 위한 비용
 * 비용은 양의 정수이며, W[i][i]=0 , i에서 도시 j로 갈 수 없는 경우, W[i][j]=0
 * <입력>
 * 1_문자열_누적합_구현) 도시의 수 N (2_Graph_DFS_BFS ≤ N ≤ 16)
 * N개 줄) 비용 행렬 W (W[i][j]는 i에서 j로 가기 위한 비용) (0 <= W[i][j] <= 1e6 , 갈 수 없는 경우, 0)
 * <출력> 순회에 필요한 최소 비용
 */

/**
 * <DP>
 * 기저사례, 메모이제이션, 로직, 초기화
 */

int W[16][16];
int dp[16][1<< 16];
int n;

int tsp(int here, int visited) { //visited 배열처럼 사용 (비트마스킹)
    //기저 사례 : 모두 방문
    if(visited == (1 << n) - 1) {
        return W[here][0] ? W[here][0] : INF;
    }

    //메모이제이션
    int &ret = dp[here][visited];
    if(ret != -1) //이미 있다면
        return ret;

    //로직
    ret = INF; //최대 -> 최소
    for(int i = 0; i < n; i++) {
        if(visited & (1 << i)) //이미 방문
            continue;
        if(W[here][i] == 0) //길이 없음
            continue;
        ret = min(ret, tsp(i, visited | (1 << i)) + W[here][i]);
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }

    //초기화
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << '\n';

    return 0;
}

