//
// Created on 2024-03-21.
//
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m, ret;
string b[55];
int dist[55][55];

void init() {
    for (int i = 0; i < 55; i++) fill(dist[i], dist[i] + 55, -1);
}

void bfs(int r, int c) {
    queue<pair<int, int>> Q;
    int maxL = 0;
    dist[r][c] = 0;
    Q.push({r, c});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (dist[nx][ny] != -1 || b[nx][ny] == 'W') continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            maxL = max(maxL, dist[nx][ny]);
            Q.push({nx, ny});
        }
    }
    ret = max(ret, maxL);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == 'L') {
                init();
                bfs(i, j);
            }

        }
    }
    cout << ret;
    return 0;
}
