//
// Created on 2024-04-23.
//
#include <iostream>

using namespace std;
int a[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //선발명단 선발 - 성의 첫 글자가 같은 서수 5명, 5명 안되면 기권
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[s[0] - 'a']++;
    }
    bool flag = false;
    for (int i = 0; i < 26; i++) {
        if (a[i] < 5) continue;
        flag = true;
        cout << (char) (i + 'a');
    }
    if (!flag) cout << "PREDAJA";
    return 0;
}