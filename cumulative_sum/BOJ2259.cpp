//
// Created on 2024-04-23.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    cin >> v[0];
    for (int i = 1; i < n; i++) {
        int t;
        cin >> t;
        v[i] = v[i - 1] + t;
    }
    int answer = v[k - 1];
    for (int i = k; i < n; i++) {
        answer = max(answer, v[i] - v[i - k]);
    }
    cout << answer;

}