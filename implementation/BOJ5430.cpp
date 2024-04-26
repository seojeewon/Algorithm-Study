//
// Created on 2024-04-26.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
string cmd, a;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;  //테스트 횟수
    cin >> t;
    while (t--) {
        cin >> cmd; //명령
        cin >> n;   //배열의 크기
        deque<int> arr; //배열
        cin >> a;   //string으로 표현된 배열
        //string을 int 배열로 변환
        int idx = 0;
        while (idx < a.size()) {
            if ((idx < a.size()) && (a[idx] == '[' || a[idx] == ']' || a[idx] == ',')) {
                idx++;
                continue;
            }
            string tmp = "";
            while ((idx < a.size()) && (a[idx] != '[' && a[idx] != ']' && a[idx] != ',')) {
                tmp += string(1, a[idx++]);
            }
            arr.push_back(stoi(tmp));
        }
        //명령 수행
        bool flag = false;  //배열이 뒤집히면 true
        bool isError = false;
        for (char c: cmd) {
            if (c == 'R') flag = !flag;
            else {
                if (arr.empty()) {
                    isError = true;
                    break;
                }
                if (flag) arr.pop_back();
                else arr.pop_front();
            }
        }
        //print
        if (isError) cout << "error\n";
        else if (arr.empty()) cout << "[]\n";
        else {
            if (flag) reverse(arr.begin(), arr.end());
            cout << "[";
            for (int i = 0; i < arr.size() - 1; i++) {
                cout << arr[i] << ",";
            }
            cout << arr[arr.size() - 1] << "]\n";
        }
    }

    return 0;
}
