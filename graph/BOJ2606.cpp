//
// Created on 2024-03-19.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, e, cnt = -1;
int vis[105];
vector<int> graph[105];

void bfs(int start) {
    queue<int> Q;
    vis[start] = 1;
    Q.push(start);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cnt++;
        for (int nxt: graph[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = 1;
            Q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    cout << cnt;
    return 0;
}
