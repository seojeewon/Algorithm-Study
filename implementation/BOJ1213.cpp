//
// Created on 2024-04-25.
//
#include <iostream>
#include <stack>

using namespace std;

int apb[26];

string palendrome() {
    string answer = "I'm Sorry Hansoo";
    //팰린드롬이 안되는 경우
    //홀수가 여러개
    int cnt=0; int idx = -1;
    for(int i=0; i<26; i++)
        if(apb[i]%2){
            cnt++;
            idx=i;
        }
    if(cnt>1) return answer;
    //팰린드롬 만들기
    answer="";
    stack<char> st;
    //홀수개 알파벳이 한개
    if(idx!=-1&&apb[idx]==1){
        for(int i=0; i<26; i++){
            if(i==idx) continue;
            for(int j=0; j<apb[i]/2; j++){
                answer+=string(1,(char)('A'+i));
                st.push((char)('A'+i));
            }
        }
        answer+=string(1,(char)('A'+idx));
        while(!st.empty()){
            answer+=string(1, st.top());
            st.pop();
        }
    }
    else{
        for(int i=0; i<26; i++){
            for(int j=0; j<apb[i]/2; j++){
                answer+=string(1,(char)('A'+i));
                st.push((char)('A'+i));
            }
        }
        if(idx!=-1) answer+=string(1,(char)('A'+idx));
        while(!st.empty()){
            answer+=string(1, st.top());
            st.pop();
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string name;
    cin >> name;
    for (char c: name) apb[c - 'A']++;
    cout << palendrome();
    return 0;
}