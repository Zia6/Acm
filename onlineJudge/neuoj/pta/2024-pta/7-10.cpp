#include<iostream>
#include<queue>
#include<set>
using namespace std;
set<int> v;
int main(){
    int n;
    cin>>n;
    int t=0;
    for(int i=0;i<n;i++){
        cin>>t;
        if(v.size()==0){
            v.insert(t);
        }
        else {
            auto s=v.lower_bound(t);
            if(s==v.end()){
                v.insert(t);
            }else {
                v.erase(s);
                v.insert(t);
            }
        }
    }
    cout<<v.size()<<'\n';
}