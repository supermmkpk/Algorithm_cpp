#include <bits/stdc++.h>
using namespace std;

/**
 * 작성자 : 박봉균
 * 아이디어 : 순열, 숫자 문자열로 처리 후 정렬(자릿수 k+1로 같으므로 OK)
 * 결과 : 3692KB, 4ms
 */

/* <BJ2529_S1 : 부등호>
 * <시간제한: 1초>
 * 두 부등호 ‘<’ , ‘>’가 k개 나열된 순서열 A가 있다.
 * 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려 한다.
 * 넣을 수 있는 숫자는 0~9 정수이며 선택된 숫자는 모두 달라야 한다.
 * 이때, 부등호 기호를 제거한 뒤, 숫자를 모두 붙였을 때 나오는 여러 정수 중 최댓값과 최솟값을 찾자.
[입력]
1) 부등호 개수 k. (2 ≤ k ≤ 9)
2) k개의 부등호 기호.
[출력]
1) k+1 자리의 최대
2) 최소 정수
(첫 자리가 0인 경우도 정수에 포함되어야 한다)
*/

int k;
char oper[10];
vector<string> v;

bool check(char x, char y, char op)
{
    if (x < y && op == '<')
        return true;
    if (x > y && op == '>')
        return true;
    return false;
}

// 0~9중 k+1 뽑는데 순서가 있다 -> 순열!! -> visited, cnt
void go(int visited, int cnt, string num)
{
    if (cnt == k + 1)
    {
        v.push_back(num);
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (visited & 1 << i)
            continue;
        if (cnt == 0 || check(num[cnt - 1], i + '0', oper[cnt - 1]))
        {
            go(visited | 1 << i, cnt + 1, num + to_string(i));
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> oper[i];
    }

    go(0, 0, "");

    sort(v.begin(), v.end()); // 길이 같으므로 문자열 정렬 OK

    cout << v[v.size() - 1] << '\n'
         << v[0] << '\n';
    return 0;
}