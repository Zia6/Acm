#include<iostream>
using namespace std;
int main(){
    int t;
    int cnt=0;
    while(cin>>t){
        ++cnt;
        if(t==250){
            cout<<cnt<<'\n';
            break;
        }
    }
}