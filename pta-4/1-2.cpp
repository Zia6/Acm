#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int n = s.size();
    for (int i = 0, j = 0; i < n;)
    {
        if(s[i]=='6'){
            j = i;
            int cnt = 0;
            while(j < n && s[j] == s[i]){
                cnt++;
                j++;
            }
            if(cnt <= 3){
                for (int k = 0; k < cnt;k++){
                    cout << 6;
                }
            }else if(cnt > 9)
                cout << 27;
                else
                    cout << 9;
                i = j;
        }else{
            cout << s[i];
            i = i + 1;
        }
    }
}