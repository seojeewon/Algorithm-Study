//
// Created on 2024-03-19.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, a[40], ret = INF;

void flip(int row) {
    // n번째 행까지 다 뒤집음 -> 이제 각 열을 뒤집기
    if (row == n + 1) {
        int sum = 0;    //행 경우의 수의 최소 뒷면 개수 저장
        for (int i = 1; i <= 1 << (n - 1); i *= 2) {
            int cnt = 0;    //i번째 열에 있는 뒷면 개수
            for (int j = 1; j <= n; j++) {
                if (a[j] & i) cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }
    //1 . {row}행 안 뒤집는 경우
    flip(row + 1);
    //2. {row}행 뒤집는 경우
    a[row] = ~a[row];    //~는 모든 비트를 뒤집는다.
    flip(row + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s; //HHT 입력 받음
        int val = 1;
        for (int j = 0; j < s.size(); j++) {    //HHT를 001=4로 바꿔서 a에 저장
            if (s[j] == 'T')
                a[i] |= val;
            val *= 2;
        }
    }
    //각 행의 모든 경우의 수를 찾고, 각 경우의 수마다 뒷면을 최소로 만들도록 열을 뒤집는다.
    flip(1);
    cout << ret;
    return 0;
}
