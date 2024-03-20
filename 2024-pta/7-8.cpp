#include<iostream>
using namespace std;
string s;
int main(){
    int t;
    cin>>t;
    char c;
    cin>>c;
    getchar();
    getline(cin,s);
    int len=s.size();
    if(len>=t){
        cout<<s.substr(len-t,t)<<'\n';
    }else{
        for(int i=0;i<t-len;i++){
            cout<<c;
        }
        cout<<s<<'\n';
    }
}