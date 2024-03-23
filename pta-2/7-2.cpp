#include<iostream>
using namespace std;
int main(){
    int y,m,dd;
    string s;
    cin>>s;
    for(int i=6;i<=9;i++)
    cout<<s[i];
    cout<<'-';
    for(int i=0;i<=4;i++){
        cout<<s[i];
    }
}