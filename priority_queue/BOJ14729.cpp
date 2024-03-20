//
// Created on 2024-03-20.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
priority_queue<double> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    //n이 너무 큼->배열에 다 저장하는 것이 부담스럽다->우선순위 큐
    for (int i = 0; i < n; i++) {
        double score;
        cin >> score;
        if (pq.size() != 7)
            pq.push(score);
        else {
            //성적이 제일 안 좋은 7명만 남으면 된다.
            //따라서 매번 성적이 좋은 애(루트노드)를 버리면 마지막에는 성적이 좋지 않은 7명만 남는다.
            pq.push(score);
            pq.pop();
        }
    }
    double ans[7];
    for (int i = 0; i < 7; i++) {
        ans[i] = pq.top();
        pq.pop();
    }
    cout << fixed;
    cout.precision(3);
    for (int i = 6; i >= 0; i--)
        cout << ans[i] << '\n';
    return 0;
}
