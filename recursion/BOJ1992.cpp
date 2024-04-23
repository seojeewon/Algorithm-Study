//
// Created on 2024-04-23.
//
#include <iostream>

using namespace std;
int n;
string s[68];

string rec(int x, int y, int size) {
    if (size == 1) return string(1, s[x][y]);
    char std = s[x][y];
    string ans = "";
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (std != s[i][j]) {
                ans += "(";
                ans += rec(x, y, size / 2);
                ans += rec(x, y + size / 2, size / 2);
                ans += rec(x + size / 2, y, size / 2);
                ans += rec(x + size / 2, y + size / 2, size / 2);
                ans += ")";
                return ans;
            }
        }
    }
    return string(1, std);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)cin >> s[i];
    cout << rec(0, 0, n);
}
