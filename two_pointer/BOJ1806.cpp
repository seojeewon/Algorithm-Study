//
// Created on 2024-03-27.
//
#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7fffffff;
int n, s, ret=INF;
int a[100006];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int en=0; int sum=a[0];
    for(int st=0;st<n;st++){
        while(en<n&&sum<s){
            en++;
            if(en!=n) sum+=a[en];
        }
        if(en == n) break;
        ret = min(en-st+1, ret);
        sum-=a[st];
    }
    if(ret==INF){
        cout<<0;
    }
    else cout<<ret;
    return 0;
}
