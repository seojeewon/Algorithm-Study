//
// Created on 2024-04-23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max(int a, int b, int c) {
    int ab = max(a, b);
    int nc = max(ab, c);
    return nc;
}

int min(int a, int b, int c) {
    int ab = min(a, b);
    int nc = min(ab, c);
    return nc;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> preMax(3,0), preMin(3,0), cur(3,0),maxi(3,0), mini(3,0);
    cin >> preMax[0] >> preMax[1] >> preMax[2];
    for(int i=0; i<3; i++)preMin[i]=preMax[i];
    for (int i = 1; i < n; i++) {
        cin >> cur[0] >> cur[1] >> cur[2];
        maxi[0]=cur[0]+max(preMax[0], preMax[1]);
        maxi[1]=cur[1]+max(preMax[0], preMax[1], preMax[2]);
        maxi[2]=cur[2]+max(preMax[1], preMax[2]);
        mini[0]=cur[0]+min(preMin[0], preMin[1]);
        mini[1]=cur[1]+min(preMin[0], preMin[1], preMin[2]);
        mini[2]=cur[2]+min(preMin[1], preMin[2]);
        preMax=maxi;
        preMin=mini;
    }
    sort(preMax.begin(), preMax.end());
    sort(preMin.begin(), preMin.end());
    cout << preMax[2] << " " << preMin[0];
}