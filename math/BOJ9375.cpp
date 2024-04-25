//
// Created on 2024-04-24.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num = 1;
        vector<int> v(35, 0);
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            if (m[type]) {
                v[m[type]]++;
            } else {
                m[type] = num++;
                v[m[type]]++;
            }
        }
        int ans = 1;
        for (int i = 1; i <= num; i++)
            ans *= (v[i] + 1);
        cout << ans - 1 << "\n";
    }
}
