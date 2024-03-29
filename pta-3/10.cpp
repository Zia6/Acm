#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
vector<int> ans;
vector<int> v[N];
queue<int> q;
int dep[N];
int main(){
    int n, t;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if(t>0)
            v[t].push_back(i);
        else
            v[0].push_back(i);
    }
    int m = 0;
    q.push(0);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size();i++){
            int u = v[now][i];
            dep[u] = dep[now] + 1;
            m = max(m, dep[u]);
            q.push(u);
        }
    }
    for (int i = 1; i <= n;i++){
        if(dep[i]==m){
            ans.push_back(i);
        }
    }
    cout << m << '\n';
    for (int i = 0; i < ans.size();i++){
        cout << ans[i];
        if(i!=ans.size()-1)
            cout << ' ';
    }
}