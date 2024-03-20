#include<iostream>
#include<queue>
using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    int t=0;
    for(int i=0;i<n;i++){
        cin>>t;
        int flag=0;
        int x=v.size();
        int maxv=0;
        if(x==0){
            v.push_back(t);
            maxv=max(maxv,t);
            continue;
        }
    }
    cout<<v.size()<<'\n';
}