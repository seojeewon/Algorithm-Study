//
// Created on 2024-03-22.
//
#include <iostream>

using namespace std;

long long dp[95];

long long fib(int n) {
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}
