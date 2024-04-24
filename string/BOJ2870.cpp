//
// Created on 2024-04-24.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<string> v;   //숫자 저장
void find(string s) {
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            string tmp = string(1, s[i++]);
            while (s[i] >= '0' && s[i] <= '9') tmp += string(1, s[i++]);
            if (tmp.size() > 1 && tmp[0] == '0') {
                while (tmp.size() > 1 && tmp[0] == '0') tmp.erase(0, 1);
            }
            v.push_back(tmp);
        }
    }
}

bool cmp(string &s1, string &s2) {
    if (s1.size() == s2.size()) return s1 < s2;
    return s1.size() < s2.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        find(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (const string &x: v) cout << x << "\n";
    return 0;
}
