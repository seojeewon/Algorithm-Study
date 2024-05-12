//
// Created on 2024-05-12.
//
#include <iostream>

using namespace std;
string board[102];
int ans[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> board[i];
    for (int i = 0; i < h; i++) fill(ans[i], ans[i] + w, -1);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 'c') {   //처음부터 구역 (i, j) 에 구름이 떠 있었던 경우에는 0
                ans[i][j] = 0;
                int cnt = 0, idx = j;
                while (j < w && board[i][++j] == '.') ans[i][j] = ++cnt;
                j = idx;
            }

        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
}