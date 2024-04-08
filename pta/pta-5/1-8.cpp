#include<iostream>
using namespace std;
const int maxn = 3;
int a[maxn][maxn], ans[maxn][maxn];
int vis[10];
int va[19] = {10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 306, 1080, 144, 1800, 3600};
int main(){
    int t1, t2;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            cin >> a[i][j];
            vis[a[i][j]] = 1;
            if(a[i][j] == 0){
                t1 = i, t2 = j;
            }
        }
    }
    for (int i = 1; i <= 9;i++){
        if(!vis[i]){
            a[t1][t2] = i;
            ans[t1][t2] = i;
            break;
        }
    }
    // cout << ans[t1][t2] << '\n';
    int x, y;
    for (int i = 0; i < 3;i++){
        cin >> x >> y;
        ans[x - 1][y - 1] = a[x - 1][y - 1];
        cout << a[x - 1][y - 1] << '\n';
    }
    int k;
    cin >> k;
    int cnt = 0;
    if(k <= 3){
        for (int i = 0; i < 3;i++){
            cnt += ans[k - 1][i];
        }
    }else if(k <= 6){
        for (int i = 0; i < 3;i++){
            cnt += ans[i][k - 4];
        }
    }else if(k == 7){
        cnt = cnt + ans[0][0] + ans[1][1] + ans[2][2];
    }else
        cnt = cnt + ans[0][2] + ans[1][1] + ans[2][0];
    if(cnt < 6)
        cout << 0;
    else 
    std::cout << va[cnt - 6];
}