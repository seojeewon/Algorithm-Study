//
// Created by jw070 on 2024-03-19.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int n, m, ret;
string s[102];
int dist[102][102];

void bfs() {
    dist[0][0] = 1;
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (s[nx][ny] != '1' || dist[nx][ny] != 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    bfs();
    cout << dist[n - 1][m - 1];
    return 0;
}
