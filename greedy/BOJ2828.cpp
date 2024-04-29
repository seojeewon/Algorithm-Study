//
// Created on 2024-04-25.
//
#include <iostream>
#include <stack>

using namespace std;

int n, m, j;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> j;
    int st = 1; //바구니 시작 위치
    int ans = 0;
    for (int i = 0; i < j; i++) {
        int loc;
        cin >> loc;
        if (st <= loc && (loc - st) < m) continue; //움직이지 않는다
        //움직여야 하는 경우
        if (loc > st) {
            ans += loc - st - m + 1;
            st = loc - m + 1;
        } else {
            ans += st - loc;
            st = loc;
        }
    }
    cout << ans;
    return 0;
}
