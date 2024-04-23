//
// Created on 2024-04-23.
//
#include <iostream>
#include <vector>

#define ll long long
using namespace std;

ll n;
ll m1, zero, p1;

void rec(vector<vector<int>> &b, int x, int y, int size) {
    if (size == 1) {
        if (b[x][y] == -1) m1++;
        else if (b[x][y] == 0) zero++;
        else p1++;
        return;
    }
    int std = b[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (std != b[i][j]) {
                rec(b, x, y, size / 3);
                rec(b, x, y + size / 3, size / 3);
                rec(b, x, y + 2 * size / 3, size / 3);
                rec(b, x + size / 3, y, size / 3);
                rec(b, x + size / 3, y + size / 3, size / 3);
                rec(b, x + size / 3, y + 2 * size / 3, size / 3);
                rec(b, x + 2 * size / 3, y, size / 3);
                rec(b, x + 2 * size / 3, y + size / 3, size / 3);
                rec(b, x + 2 * size / 3, y + 2 * size / 3, size / 3);
                return;
            }
        }
    }
    if (std == -1) {
        m1++;
    } else if (std == 0) {
        zero++;
    } else {
        p1++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<vector<int>> b(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> b[i][j];
    }
    rec(b, 0, 0, n);
    cout << m1 << "\n" << zero << "\n" << p1;
}