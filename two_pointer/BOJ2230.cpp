//
// Created on 2024-03-27.
//
#include <iostream>
#include <algorithm>

using namespace std;
const int INF = (1 << 31)-1;
int n, m, ret=INF;
int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //두 수의 차이가 M 이상이면서 제일 작은 경우
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    //정렬
    sort(a, a + (n + 1));
    int en = 2;
    for (int st = 1; st < n; st++) {
        while (en <= n && a[en] - a[st] < m) en++;
        if(en>n) break;
        if(a[en]-a[st]>=m){
            ret = min(ret, a[en]-a[st]);
        }
    }
    cout<<ret;
    return 0;
}
