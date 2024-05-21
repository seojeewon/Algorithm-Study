#include <iostream>
#include <climits>
using namespace std;

// 정점의 수를 상수로 정의
#define V 5

// 최소 키 값을 찾는 보조 함수
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// 최소 신장 트리를 구성하고 결과를 출력하는 함수
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

// Prim 알고리즘을 사용하여 최소 신장 트리를 찾는 함수
void primMST(int graph[V][V]) {
    int parent[V]; // 최소 신장 트리를 저장하는 배열
    int key[V]; // 각 정점의 키 값

    bool mstSet[V]; // 최소 신장 트리에 포함된 정점을 나타내는 배열

    // 초기화: 모든 키 값을 INT_MAX로 설정하고, mstSet을 false로 초기화
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // 시작점을 선택하여 키 값을 0으로 설정
    key[0] = 0;
    parent[0] = -1; // 첫 번째 노드는 시작점이므로 부모를 설정하지 않음.

    // 최소 신장 트리에 V-1개의 정점을 추가
    for (int count = 0; count < V - 1; count++) {
        // 최소 키 값을 가진 정점을 선택
        int u = minKey(key, mstSet);

        // 해당 정점을 최소 신장 트리에 추가
        mstSet[u] = true;

        // 선택된 정점과 연결된 정점들의 키 값을 업데이트
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // 최소 신장 트리를 출력
    printMST(parent, graph);
}

int main() {
    // 그래프의 인접 행렬을 정의
    int graph[V][V] = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
    };

    // Prim 알고리즘을 호출하여 최소 신장 트리를 찾음
    primMST(graph);

    return 0;
}
