#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 5;
char xingbie[N];
vector<int> v[N];
int vis[N];
void dfs(int x,int cnt)
{
    if(cnt>=3){
        return;
    }
    vis[x]=1;
    for(int i=0;i<v[x].size();i++){
        dfs(v[x][i],cnt+1);
    }
}
void dfs3(int x,int cnt){
    if(cnt>=3){
        return;
    }
    vis[x]=0;
    for(int i=0;i<v[x].size();i++){
        dfs3(v[x][i],cnt+1);
    }

}
int dfs2(int x,int cnt){
    if(cnt>=3){
        return 0;
    }
    if(vis[x]){
        return 1;
    }
    for(int i=0;i<v[x].size();i++){
        if(dfs2(v[x][i],cnt+1)){
            return 1;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v1, v2;
        cin >> u;
        getchar();
        cin>>xingbie[u] >> v1 >> v2;
        if (v1 != -1)
        {
            v[u].push_back(v1);
            // cout<<u<<' '<<v1<<'\n';
        }
        if (v2 != -1)
        {
            v[u].push_back(v2);
            // cout<<u<<' '<<v2<<'\n';
        }
    }
    int k;
    cin>>k;
    while(k--){

        int x,y;
        cin>>x>>y;
        if(xingbie[x]==xingbie[y]){
            cout<<"Never Mind"<<'\n';
            continue;
        }
        dfs(x,0);
        if(dfs2(y,0)){
            cout<<"No"<<'\n';
        }
        else{
            cout<<"Yes"<<'\n';
        }
        dfs3(x,0);

    }
}
int main()
{
    solve();
}