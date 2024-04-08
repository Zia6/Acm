#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;
const int maxn = 1e4 + 5;
vector<int> v[maxn];
int in[maxn], fa[maxn];
int dep[maxn], vis[maxn];
vector<int> ans;
queue<int> q;
stack<int> s;
int main(){
    memset(fa, -1, sizeof(fa));
    int n, m, t, st, en = 0;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> m;
        for (int j = 0; j < m;j++){
            cin >> t;
            v[i].push_back(t);
            in[t]++;
        }
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < n;i++){
        if(!in[i]){
            st = i;
            break;
        }
    }
    q.push(st);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < (int)v[now].size();i++){
            int te = v[now][i];
            if(dep[now] + 1 >dep[te]){
                q.push(te);
                dep[te] = dep[now] + 1;
                fa[te] = now;
            }
        }
    }
    int max_dep = 0;
    for (int i = 0; i < n;i++){
        max_dep = max(max_dep, dep[i]);
    }
    s.push(st);
    while(!s.empty()){
        int now = s.top();
        bool flag = false;
        for (int i = 0; i < v[now].size();i++){
            if(!vis[v[now][i]]){
                s.push(v[now][i]);
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        if(dep[now] == max_dep){
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
            break;
        }
        vis[now] = true;
        s.pop();
    }
    cout << ans.size()<<'\n';
    for (int i = ans.size() - 1; i >= 0;i--){
        cout << ans[i];
        if(i > 0)
            cout << ' ';
    }
}