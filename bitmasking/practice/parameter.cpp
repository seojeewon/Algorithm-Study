//
// Created on 2024-03-14.
//
#include <iostream>

using namespace std;

const int n = 4;
string fruits[n] = {"apple", "strawberry", "pear", "grapefruit"};

void go(int num) {
    string ret = "";
    for (int i = 0; i < n; i++) {
        if (num & (1 << i)) {
            ret += fruits[i] + " ";
        }
    }
    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < n; i++) {
        //0번째 과일인 사과는 조합에 포함되고, 사과로 만들 수 있는 pair 모두 출력
        go(1 | (1 << i));
    }
    return 0;
}
