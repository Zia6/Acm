#include<iostream>
#include<set>
using namespace std;
const int N=1e4+5;
set<int> s;
int fa[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    if(x>y)  swap(x,y);
    int t1=find(x);
    int t2=find(y);
    fa[t1]=fa[t2];
}
int main(){
    for(int i=0;i<N;i++){
        fa[i]=i;
    }
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++){
        int k,m,tem;
        cin>>k;
        if(k>0) cin>>tem;
        s.insert(tem);
        for(int i=1;i<k;i++){
            cin>>m;
            s.insert(m);
            merge(m,tem);
        }
    }
    cout<<s.size()<<' ';
    int ans=0;
    for(int i:s){
        if(find(i)==i){
            ans++;
        }
    }
    cout<<ans<<'\n';
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(find(x)==find(y)){
            cout<<"Y"<<'\n';
        }else cout<<"N"<<'\n';
    }
}