//
// Created  on 2024-05-12.
//
#include <iostream>

using namespace std;

int number = 6; //정점 개수
int INF = 10000000;
int a[6][6] = {
        {0, 2, 5, 1, INF, INF},
        {2, 0, 3, 2, INF, INF},
        {5, 3, 0, 3, 1, 5},
        {1, 2, 3, 0, 1, INF},
        {INF, INF, 1, 1, 0, 2},
        {INF, INF, 5, INF, 2, 0}
};

bool vis[6];    //방문한 노드
int dist[6];    //거리

int findMinIdx(){
    int minimum = 10000000, idx = -1;
    for(int i=0; i<number; i++){
        if(!vis[i] && dist[i]<minimum){
            idx = i;
            minimum = dist[i];
        }
    }
    return idx;
}

bool isDone(){
    bool flag = true;
    for(int i=0; i<number; i++){
        if(!vis[i]) flag = false;
    }
    return flag;
}

void dijkstra(int st){
    //1. 시작 노드에서의 최소 거리
    vis[st]=true;
    for(int i=0; i<number; i++) dist[i]=a[0][i];
    //2. 방문하지 않은 노드 중에서 최소인 노드 찾기
    while(!isDone()){
        int nxt = findMinIdx();
        vis[nxt]=true;
        for(int i=0; i<number; i++){
            if(dist[i]>dist[nxt]+a[nxt][i])
                dist[i]=dist[nxt]+a[nxt][i];
        }
    }
}

int main() {
    dijkstra(0);    //0번 노드에서 출발하여 다른 모든 노드까지 최소 경로
    for(int d : dist) cout<<d<<" ";
    return 0;
}