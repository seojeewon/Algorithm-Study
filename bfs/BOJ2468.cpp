//
// Created on 2024-03-19.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, minH = INF, maxH, ret;
int arr[105][105];
int vis[105][105];

//h보다 높은 안전지대의 개수를 센다.
void bfs(int h) {
    //vis 초기화
    for (int i = 0; i < n; i++) fill(vis[i], vis[i] + 105, 0);
    queue<pair<int, int>> Q;
    int cnt = 0;    //안전지대 개수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || arr[i][j] <= h) continue;
            vis[i][j] = 1;
            cnt++;
            Q.push({i, j});
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny] || arr[nx][ny] <= h) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    ret = max(ret, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            minH = min(minH, arr[i][j]);    //(가장 낮은 높이-1)에서는 안전 영역 1개
            maxH = max(maxH, arr[i][j]);    //가장 높은 높이면 안전 영역 0개
        }
    }
    ret = 1;
    //비가 내리는 양에 따라 bfs 수행해서 안전 영역 각자 계산하기 최대 100*O(10000)
    for (int i = minH; i < maxH; i++) {
        bfs(i);
    }

    cout << ret;
    return 0;
}
