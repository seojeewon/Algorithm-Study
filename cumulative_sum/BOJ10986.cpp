//
// Created on 2024-03-28.
//
#include <iostream>
#include <algorithm>
#include <queue>

#define ll long long

using namespace std;
int n, m;
ll preSum = 0l, ret = 0l;
ll mod[10002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        preSum += t;
        mod[preSum % m]++;
    }

    for (int i = 0; i < m; i++) {
        ret += (mod[i] * (mod[i]-1)) / 2;
    }
    ret += mod[0];
    cout << ret;
    return 0;

}
