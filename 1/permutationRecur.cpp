#include <bits/stdc++.h>
using namespace std;

void printV(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

vector<int> v;
void makePermutation(int n, int r, int depth) {
    cout << n << " : " << r << " : " << depth << '\n';
    if(r == depth) {
        printV(v);
        return;
    }
    for(int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]); //원복
    }
    return;
}
int main() {
    for(int i = 1; i <= 3; i++ ) {
        v.push_back(i);
    }
    makePermutation(3,3,0);

    return 0;
}
