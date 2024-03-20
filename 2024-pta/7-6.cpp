#include<iostream>
#include<deque>
using namespace std;
deque<string> d1,d2;
int t[51];
    string s[55];
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>t[i]>>s[i];
        if(t[i]==0){
            d1.push_back(s[i]);
        }else{
            d2.push_back(s[i]);
        }
    }
    for(int i=0;i<(n>>1);i++){
        if(t[i]==0){
            cout<<d1.front()<<' '<<d2.back()<<'\n';
            d1.pop_front();
            d2.pop_back();
        }else{
            cout<<d2.front()<<' '<<d1.back()<<'\n';
            d2.pop_front();
            d1.pop_back();
        }
    }
}