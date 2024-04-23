#include<iostream>
#include <string.h>
using namespace std;
const int maxn = 305;
const int inf = 1e9 + 5;
int v[maxn][maxn];
bool vis1[maxn][maxn], vis2[maxn];
int cnt = 0;
int ve[maxn];
int main(){
    int n, m, index, count = 0, co = 0;
    cin >> n >> m;
    int ans = inf;
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= n;j++){
            v[i][j] = inf;
        }
    }
    for (int i = 0; i < m;i++){
        int st, en, w;
        cin >> st >> en >> w;
        v[st][en] = min(v[st][en], w);
        v[en][st] = min(v[en][st], w);
        vis1[st][en] = true;
        vis1[en][st] = true;
    }
    int k;
    cin >> k;
    while(k--){
        count++;
        int nn, tmp = 0;
        cnt = 0;
        memset(vis2, false, sizeof(vis2));
        cin >> nn;
        bool flag = true;
        ve[cnt++] = 0;
        for (int i = 0; i < nn;i++){
            int te;
            cin >> te;
            if(!vis1[ve[cnt - 1]][te] || vis2[te]){
                flag = false;
            }
            if(vis1[ve[cnt - 1]][te])
                tmp += v[ve[cnt - 1]][te];
            ve[cnt++] = te;
            vis2[te] = true;
        }
        if(vis1[ve[cnt - 1]][0]){
            tmp += v[ve[cnt - 1]][0];
        }else flag =false;
        for (int i = 1; i <= n;i++){
            if(!vis2[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            co++;
            if(tmp < ans){
                ans = min(tmp, ans);
                index = count;
            }
        }
    }
    cout <<co<<'\n'<<index<<' '<<ans << '\n';
}