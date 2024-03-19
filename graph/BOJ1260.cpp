//
// Created on 2024-03-19.
//
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n, m, s;
vector<int> graph[1010];
int vis[1010];

//비재귀 dfs - 이론적 dfs 순서대로 하려면 실제 방문했을 때 발자국 찍어야 한다.
void dfs_v2() {
    stack<int> st;
    st.push(s);
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        cout << cur << ' ';
        int size = graph[cur].size();
        for (int i = size - 1; i >= 0; i--) {
            if (vis[graph[cur][i]]) continue;
            st.push(graph[cur][i]);
        }
    }
}

//재귀 dfs
void dfs(int vertex) {
    vis[vertex] = 1;
    cout << vertex << ' ';
    for (int dir = 0; dir < graph[vertex].size(); dir++) {
        if (vis[graph[vertex][dir]]) continue;
        dfs(graph[vertex][dir]);
    }
    return;
}

void bfs() {
    queue<int> Q;
    fill(vis, vis + 1010, 0); //초기화
    vis[s] = 1;
    Q.push(s);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        cout << cur << ' ';
        for (int dir = 0; dir < graph[cur].size(); dir++) {
            if (vis[graph[cur][dir]]) continue;
            vis[graph[cur][dir]] = 1;
            Q.push(graph[cur][dir]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //인접리스트 정렬
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(s);
    //dfs_v2();
    cout << '\n';
    bfs();
    return 0;
}
