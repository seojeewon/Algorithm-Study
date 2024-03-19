//
// Created by jw070 on 2024-03-19.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, ret;
vector<int> list[1010];
int vis[1002];    //방문한 정점

void bfs(){
    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        ret++;  //영역 발견
        Q.push(i);
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            //이웃 정점 확인
            for(int dir=0;dir<list[cur].size();dir++){
                if(vis[list[cur][dir]]) continue;
                vis[list[cur][dir]]=1;
                Q.push(list[cur][dir]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        //무방향 그래프
        list[u].push_back(v);
        list[v].push_back(u);
    }

    bfs();
    cout << ret;
    return 0;
}
