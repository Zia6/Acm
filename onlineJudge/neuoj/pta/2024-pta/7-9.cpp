#include<iostream>
#include<vector>
using namespace std;
const int N=505;
vector<int> g[N];
int fa[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        if(fx>fy){
            swap(fx,fy);
        }
        fa[fx]=fy;
    }
}
int a[N];
int vis[N];
int ans[N];
int q[N];
void solve(){
    int n,m,k;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
        q[a[i]]=1;
    }
    for(int i=0;i<n;i++){
        fa[i]=i;
    }
    int la=0,now;
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            if(!q[i]&&!q[g[i][j]]){
                merge(g[i][j],i);
            }
        }
    }
    for(int i=0;i<n;i++){
        if((!q[i]||vis[i])&&find(i)==i){
            la++;
        }
    }
    for(int i=k-1;i>=0;i--){
        vis[a[i]]=1;
        fa[a[i]]=a[i];
        for(int j=0;j<g[a[i]].size();j++){
            if(vis[g[a[i]][j]]||!q[g[a[i]][j]]){
                merge(g[a[i]][j],a[i]);
            }
        }
        int cnt=0;
        for(int j=0;j<n;j++){
            if((!q[j]||vis[j])&&find(j)==j){
                cnt++;
            }
        }
        // cout<<cnt<<'\n';
        now=cnt;
        if(now==la+1||now==la){
            ans[i]=1;
        }
        la=now;
    }
    for(int i=0;i<k;i++){
        if(!ans[i]){
            cout<<"Red Alert: ";
        }
        cout<<"City "<<a[i]<<" is "<<"lost."<<'\n';

    }
    if(k==n)
    cout<<"Game Over."<<'\n';
}
int main(){
    solve();
}