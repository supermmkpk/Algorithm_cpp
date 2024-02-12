#include <bits/stdc++.h>
using namespace std;

/*
 *  영선이는 초대장을 돌렸는데, 받은 사람들이 언제 와서 언제 떠날 것인지 답변을 줬다.
 *  욱제는 자신을 제외한 파티 인원이 T명 미만이 되는 순간 파티장에서 나가고, T명 이상이 되는 순간 다시 돌아온다.
 *  답변을 정리하던 영선이는 파티가 진행되는 동안 T명 이상의 인원이 계속 유지되지 못 한다는 것을 알게 되었다.
 *  그래서 영선이는 급히 자신의 친구들 K명을 부르려고 한다.
 *  영선이의 친구들은 욱제 및 영선이의 친구들을 제외한 파티 인원이 T명 이상이 되는 순간 다 같이 파티장에서 나가 버리고 돌아오지 않는다.
 *   또한 파티 인원이 T명 이상이면 영선이의 친구들은 파티장에 들어가지 않는다. 단, 아직 들어오지 않은 영선이의 친구들은 이후 파티 인원이 T명 미만이 되면 파티장으로 들어 갈 수 있다.
 *   영선이는 친구들 각각을 적절한 시각에 투입시켜 최대한 오랫동안 욱제가 파티에 머물도록 하고 싶다. 꼭 K명을 모두 투입시킬 필요는 없다.
 *   영선이는 욱제를 얼마나 오래 파티에 머물게 할 수 있을까?
[입력]
1) 파티가 진행되는 시간 N, 파티에 초대한 사람 수 M, 영선이의 친구 수 K, 기대하는 최소의 파티 인원 T (1 ≤ N ≤ 300, 1 ≤ M ≤ 300, 1 ≤ K ≤ 300, 1 ≤ T ≤ M).
M개 줄) ai, bi가 주어진다. i번째 사람은 ai에 파티에 참여하고, bi에 파티를 떠난다. (1 ≤ ai ≤ N, ai < bi ≤ N + 1)
파티가 시작되는 시각은 1을 기준으로 한다.

[출력]
영선이의 친구들을 파티에 투입시켰을 때 욱제가 파티에 머무를 수 있는 최대 시간을 출력한다.
 */
int nPerTime[304];
int dp[304][304]; //상태값: 현재시간, 남아있는 영선의 친구수
vector<pair<int, int>> section;

int N, M, K, T;

int go(int now, int remain, int prev) {
    //기처사례
    if(now == section.size())
        return 0;

    //메모이제이션
    if(dp[now][remain])
        return dp[now][remain];

    //로직
    int need = max(0, T - section[now].second);
    int real_need = (prev >= need) ? 0 : need - prev;
    if(remain >= real_need)
        return dp[now][remain] = max(go(now + 1, remain - real_need, need) + section[now].first, go(now + 1, remain, 0));
    else
        return dp[now][remain] = go(now + 1, remain, 0);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K >> T;

    for(int i = 0; i < M; i++) {
        int tmpA, tmpB;
        cin >> tmpA >> tmpB;
        for(int j = tmpA; j < tmpB; j++)
            nPerTime[j] = min(T, ++nPerTime[j]);
    }

    int prev = nPerTime[1];
    int cnt = 1;
    for(int i = 2; i <= N; i++) {
        if(prev != nPerTime[i]) { //구간 표현: 구간 길이, 사람수
            section.push_back({cnt, prev});
            cnt = 0;
            prev = nPerTime[i];
        }
        cnt++;
    }
    section.push_back({cnt, prev});
    cout << go(0, K, 0) << '\n';

    return 0;
}