#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> v[maxn];
int in[maxn], dep[maxn];
int ans = 0;
void dfs(int x){
    for (int i = 0; i < v[x].size();i++){
        int u = v[x][i];
        dep[u] = dep[x] + 1;
        if(dep[u] > dep[ans]){
            ans = u;
        }
        dfs(u);
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int k;
        cin >> k;
        while(k--){
            int t;
            cin >> t;
            v[i].push_back(t);
            in[t]++;
        }
    }
    int st = 0;
    for (int i = 1; i <= n;i++){
        if(in[i] == 0){
            st = i;
            break;

        }
    }
    dfs(st);
    // for (int i = 1; i <= n;i++){
    //     cout << dep[i] << ' ';
    // }
        // cout << st << '\n';
    if(ans != 0)
    cout << ans;
    else
        cout << st;
}