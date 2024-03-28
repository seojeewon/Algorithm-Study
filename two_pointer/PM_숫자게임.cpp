//
// Created on 2024-03-28.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//A팀이 출전순서 공개한 걸 바탕으로 B팀은 자기들이 승점이 높도록 출전 순서 정한다.
//이때 B팀이 얻는 승점
//순서보다는 걍 최대 몇명 이길 수 있는지 구하기
//2, 2, 6, 8
//1, 3, 5, 7
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int n = A.size();
    //A, B 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int en = 0, pre=-1;
    for(int st = 0 ; st<n ; st++){
        //B는 A보다 큰 것중에 제일 작은 수를 줘야함
        if(B[st]>A[en]){
            en++;
            answer++;
        }
    }
    return answer;
}