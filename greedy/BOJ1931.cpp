//
// Created on 2024-03-20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }
    //회의가 끝나는 시간이 빠른 순으로 회의를 채워넣으면 된다.
    //1. 끝나는 시간 순으로 정렬
    sort(v.begin(), v.end(), cmp);
    auto prior = v[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].first >= prior.second) {
            prior = v[i];
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
