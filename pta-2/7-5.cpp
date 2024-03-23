#include<iostream>
#include<set>
using namespace std;
int main(){
    string s;
    int a,b,n;
    cin>>n;
    while(n--){
        cin>>s>>a>>b;
        if(a>=15&&a<=20&&b>=50&&b<=70)
        continue;
        else cout<<s<<'\n';
    }
}