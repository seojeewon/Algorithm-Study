//
// Created on 2024-04-23.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

long long bfs(long long a, long long b) {
    queue<long long> Q;
    map<long long,int> M;
    M[a] = 1;
    Q.push(a);
    while (!Q.empty()) {
        long long cur = Q.front();
        Q.pop();
        for (long long nx: {cur * 2, cur * 10 + 1}) {
            if (nx > 1000000000 || nx > b) continue;
            if (M[nx]) continue;
            M[nx] = M[cur] + 1;
            if (nx == b) return M[nx];
            Q.push(nx);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    cout << bfs(a, b);
}