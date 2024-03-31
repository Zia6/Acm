#include<iostream>
using namespace std;
const int N = 1e4 + 5;
int in[N], cnt[N];
int vis[N], fa[N];
int prime[N];
void euler(){
    int cnt = 0;
    for (int i = 2; i < N;i++){
        if(!vis[i]){
            prime[cnt++] = i;
            fa[i] = 1;
        }
        int j = 0;
        while(j<cnt&&prime[j]*i<N){
            vis[j * i] = 1;
            j++;
        }
    }
}
int nex(int x){
    int ans = 0;
    while(x){
        int y = x % 10;
        x /= 10;
        ans += y * y;
    }
    return ans;
}
int main(){
    euler();
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        int j = nex(i);
        int cnt = 0;
        while(j!=1&&j!=i){
            cnt++;
            j = nex(j);
            cout << j << ' ';
        }
        cout << '\n';
        if(j == 1){
            if(fa[i]){
                cnt = cnt * 2;
            }
            printf("%d %d\n", i, cnt);
        }
    }
}