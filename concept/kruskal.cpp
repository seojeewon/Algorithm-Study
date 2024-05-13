//
// Created on 2024-05-13.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check[7];   //노드 연결

class Edge {
public:
    int vertex[2];  //정점
    int dist;   //가중치
    Edge(int a, int b, int dist) {
        this->vertex[0] = a;
        this->vertex[1] = b;
        this->dist = dist;
    }

    bool operator<(Edge &edge) {
        return this->dist < edge.dist;
    }
};

int getParent(int vertex) {
    if (check[vertex] == vertex) return vertex;
    return getParent(check[vertex]);
}

void unionParent(int v1, int v2) {
    v1 = getParent(v1);
    v2 = getParent(v2);
    if (v1 < v2) check[v2] = v1;
    else check[v1] = v2;
}

bool isCycle(int v1, int v2) {
    v1 = getParent(v1);
    v2 = getParent(v2);
    if (v1 == v2) return true;
    return false;
}

int main() {
    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 23));
    v.push_back(Edge(1, 2, 26));
    v.push_back(Edge(2, 3, 36));
    v.push_back(Edge(2, 4, 21));
    v.push_back(Edge(2, 5, 45));
    v.push_back(Edge(3, 5, 29));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(3, 7, 55));
    v.push_back(Edge(4, 7, 20));
    v.push_back(Edge(5, 6, 30));
    //가중치대로 오름차순 정렬
    sort(v.begin(), v.end());
    //각 정점의 부모를 본인으로 초기화
    for (int i = 0; i < 7; i++) {
        check[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!isCycle(v[i].vertex[0], v[i].vertex[1])) {
            sum += v[i].dist;
            unionParent(v[i].vertex[0], v[i].vertex[1]);
        }
    }
    cout << sum;
    return 0;
}