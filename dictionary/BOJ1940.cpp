//
// Created on 2024-05-21.
//
#include <iostream>
#include <map>

using namespace std;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    map<int, bool> M;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        M[t]=true;
    }
    int ans = 0;
    if (m % 2) {    //홀수
        for (int i = 1; i <= m / 2; i++) {
            if (M[i] && M[m - i]) ans++;
        }
    } else {  //짝수
        for (int i = 1; i < m / 2; i++) {
            if (M[i] && M[m - i]) ans++;
        }
    }
    cout << ans;
    return 0;
}