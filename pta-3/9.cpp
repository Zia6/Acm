#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4 + 5;
int n, m;
vector<int> v[N];
bool vis[N];
int fa[N];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int t1 = find(x), t2 = find(y);
    if (t1 != t2)
        fa[t2] = t1;
}
void solve(int nn)
{
    for (int i = 1; i <= n;i++){
        vis[i] = false;
    }
        for (int i = 0; i < nn; i++)
        {
            int tem;
            cin >> tem;
            vis[tem] = true;
        }
    for (int i = 1; i <= n;i++){
        if(!vis[i]){
            int siz = v[i].size();
            for (int j = 0; j < siz;j++){
                if(!vis[v[i][j]]){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int T;
    cin >> T;
    while (T--)
    {
        int nn;
        cin >> nn;
        solve(nn);
    }
}