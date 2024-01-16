#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

/*
 * 단어의 개수 N (50보다 작거나 같은 자연수)
 * 글자의 개수 K (26보다 작거나 같은 자연수 또는 0)
 * 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 모든 단어는 중복되지 않는다.
 * K개의 글자를 가르칠 때, 읽을 수 있는 단어 개수의 최댓값을 구하라.
 */
int words[54];

int count(int mask) {
    int cnt = 0;
    for(auto word : words) {
        if(word && (word & mask) == word)
            cnt++;
    }
    return cnt;

}

int go(int idx, int k, int mask) {
    if(k < 0)
        return 0; //더이상 배울 수 없음.
    if(idx == 26) //다 배움
        return count(mask);
    int ret = go(idx + 1, k - 1, mask | (1 << idx));
    if(idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a') {
        ret = max(ret, go(idx + 1, k, mask)); //antic은 반드시 배워야 하고 그게 아니면 안 가르칠 수 있다.
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(auto c : str) {
            words[i] |= (1 << (c - 'a')); // i번째 단어에 어떤 글자가 있는가?
        }
    }

    cout << go(0, k, 0) << '\n';


    return 0;
}
