//
// Created on 2024-03-14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;  //식재료 개수
int mp, mf, ms, mv; //단백질, 지방, 탄수화물, 비타민 최소 영양

bool valid(int p, int f, int s, int v) {
    if (p >= mp && f >= mf && s >= ms && v >= mv) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    vector<int> protein(n, 0);
    vector<int> fat(n, 0);
    vector<int> sugar(n, 0);
    vector<int> vitamin(n, 0);
    vector<int> cost(n, 0);

    int minCost = 0;
    for (int i = 0; i < n; i++) {
        cin >> protein[i] >> fat[i] >> sugar[i] >> vitamin[i] >> cost[i];
        minCost += cost[i];
    }

    minCost += 1;
    vector<int> result;

    for (int i = 1; i < (1 << n); i++) {
        int p = 0, f = 0, s = 0, v = 0, c = 0;
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                temp.push_back(j);
                p += protein[j];
                f += fat[j];
                s += sugar[j];
                v += vitamin[j];
                c += cost[j];
            }
        }
        if(valid(p, f, s, v) && c == minCost){  //같은 경우 사전순 출력
            vector<vector<int>> v;
            v.push_back(temp);
            v.push_back(result);
            sort(v.begin(), v.end());
            result = v[0];
        }
        else if (valid(p, f, s, v) && c < minCost) {
            minCost = c;
            result = temp;
        }
    }
    if (result.empty()) {
        cout << -1;
    } else {
        cout << minCost << '\n';
        for (int a: result) {
            cout << a + 1 << ' ';
        }
    }
    return 0;
}
