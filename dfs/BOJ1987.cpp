//
// Created on 2024-05-21.
//
#include <iostream>
#include <stack>

using namespace std;
int r, c;
string board[25];
int max_cnt;
bool isUsed[26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void func(int x, int y, int d) {
    //재귀 dfs
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (isUsed[board[nx][ny] - 'A']) continue;
        isUsed[board[nx][ny] - 'A'] = true;
        func(nx, ny, d + 1);
        isUsed[board[nx][ny] - 'A'] = false;
    }
    max_cnt = max(max_cnt, d);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }
    isUsed[board[0][0] - 'A'] = true;
    func(0, 0, 1);
    cout << max_cnt;
    return 0;
}