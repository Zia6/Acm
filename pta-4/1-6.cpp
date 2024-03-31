#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        if((s[0] - '0') + (s[1] - '0') + (s[2]-'0')==(s[3] - '0')+(s[4]-'0')+(s[5]-'0'))
            printf("You are lucky!\n");
        else
            printf("Wish you good luck.\n");
    }
}