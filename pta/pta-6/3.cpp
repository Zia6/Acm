#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    string s1, s2;
    if(s.size() == 4){
        s1 = s.substr(0, 2);
        s2 = s.substr(2, 2);
        if(stoi(s1) < 22){
            cout << 20 << s1 << '-' << s2;
        }else
            cout << 19 << s1 << '-' << s2;
    }else {
        s1 = s.substr(0, 4);
        s2 = s.substr(4, 2);
        cout << s1 << '-' << s2;
    }
}