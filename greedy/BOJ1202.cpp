//
// Created on 2024-03-20.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
long long ret;
vector<pair<int, int>> v;   //보석
int c[300008];  //가방

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int m, val;
        cin >> m >> val;
        v.push_back({m, val});
    }
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    //가벼운 가방이 자기가 가져갈 수 있는 보석 중에 제일 비싼 거 가져가면 됨
    sort(v.begin(), v.end());
    sort(c, c + k);
    priority_queue<int> pq;

    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && v[j].first <= c[i])
            pq.push(v[j++].second);
        if (!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret;
    return 0;
}
