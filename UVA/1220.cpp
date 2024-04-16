#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int maxn = 2e5 + 5;
int cnt = 0, n;
vector<int> son[maxn];
int d[maxn][2],f[maxn][2];
string s1, s2;
map<string, int> mp;
void dfs(int u){
    d[u][1] = 1;
    d[u][0] = 0;
    int l = son[u].size();
    for (int i = 0; i < l;i++){
        int v = son[u][i];
        dfs(v);
        d[u][0] += max(d[v][1], d[v][0]);
        if(d[v][1] == d[v][0]){
            f[u][0] = 1;
        }
        if(d[v][1] > d[v][0] && f[v][1]){
            f[u][0] = 1;
        }
        if(d[v][0] > d[v][1] && f[v][0]){
            f[u][0] = 1;
        }
        d[u][1] += d[v][0];
        if(f[v][0])
            f[u][1] = 1;
    }
}
int main(){
    while(cin >> n && n){
        mp.clear();
        cnt = 0;
        cin >> s1;
        if(!mp.count(s1))
                mp.insert({s1, cnt++});
        for (int i = 1; i < n;i++){
            cin >> s1 >> s2;
            if(!mp.count(s1))
                mp.insert({s1, cnt++});
            if(!mp.count(s2)){
                mp.insert({s2, cnt++});
            }
            son[mp[s2]].push_back(mp[s1]);
        }
        dfs(0);
        cout << max(d[0][1], d[0][0]) << ' ';
        if(d[0][0] == d[0][1] || (d[0][0] > d[0][1] && f[0][0])  
         || (d[0][1] > d[0][0]) && f[0][1]){
            cout << "No" << '\n';
         }else
             cout << "Yes" << '\n';
    }
}