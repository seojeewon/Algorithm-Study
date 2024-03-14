//
// Created on 2024-03-14.
//
#include <iostream>

using namespace std;

const int n = 4;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string fruits[n] = {"apple", "strawberry", "pear", "grapefruit"};

    //과일로 만들 수 있는 모든 경우의 수 = 2^4 = 16가지
    for (int i = 0; i < (1 << n); i++) {
        string result = "";
        for (int j = 0; j < n; j++) {
            //idx번째 비트가 켜져있는지 확인: if(S & (1 << idx))
            if (i & (1 << j)) {
                result += fruits[j] + " ";
            }
        }
        cout << result << '\n';
    }
    return 0;
}
