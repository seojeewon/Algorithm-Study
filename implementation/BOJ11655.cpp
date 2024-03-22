//
// Created on 2024-03-22.
//
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || (s[i] >= '0' && s[i] <= '9')) {
            cout << s[i];
            continue;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            cout << (char) ((s[i] - 'a' + 13) % 26 + 'a');
        } else {
            cout << (char) ((s[i] - 'A' + 13) % 26 + 'A');
        }
    }

    return 0;

}
