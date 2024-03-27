//
// Created on 2024-03-26.
//
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int board[180][180], dist[180][180];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int characterX, int characterY, int itemX, int itemY) {
    queue<pair<int, int>> Q;
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    dist[characterX][characterY] = 0;
    Q.push({characterX, characterY});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx > 100 || ny > 100) continue;
            if (dist[nx][ny] != -1 || board[nx][ny] != 1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            if (nx == itemX && ny == itemY) return dist[nx][ny];
            Q.push({nx, ny});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0; //이동하는 가장 짧은 거리
    for (int i = 0; i < 180; i++) fill(board[i], board[i] + 180, -1);  //초기화
    for (int i = 0; i < 180; i++) fill(dist[i], dist[i] + 180, -1);  //초기화
    //테두리를 어떻게 그려????
    //모든 좌표 2배
    for (int i = 0; i < rectangle.size(); i++) {
        for (int j = 0; j < 4; j++) {
            rectangle[i][j] *= 2;
        }
    }
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0], y1 = rectangle[i][1], x2 = rectangle[i][2], y2 = rectangle[i][3];
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                if ((j > x1 && j < x2) && (k > y1 && k < y2)) board[j][k] = 0;    //사각형 안쪽에 있는 경우
                    //사각형 테두리인데 다른 사각형의 내부가 아님->최외곽 맞음
                else if (board[j][k] != 0) board[j][k] = 1;
            }
        }
    }
    //BFS시작
    answer = bfs(characterX, characterY, itemX, itemY);
    return answer / 2;
}