#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 52;
int dp[180*maxn], v[maxn];
int n, t;
// dp[i][j] = dp[i+1][j] dp[i+1][j - v[i]] + 1
// dp[i][j] = dp[i-1][j-v[i]]+1 dp[i-1][j]
// dp[j] = dp[j-v[j]] + 1 dp[j]
int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T;i++){
        scanf("%d %d", &n, &t);
        memset(dp, -1e9-5, sizeof(dp));
        dp[0] = 0;  
        for (int j = 0; j < n; j++)
        {
            scanf("%d", v + j);
            for (int k = t - 1; k >= v[j];k--){
                dp[k] =max(dp[k - v[j]] + 1,dp[k]);
            }
        }
        int num = 0, ans = 0;
        for (int k = t - 1; k >= 0;k--){
            num = max(num, dp[k]);
        }
        for (int k = t - 1; k >= 0;k--){
            if(dp[k] == num){
                printf("Case %d: %d %d\n", i, num + 1, k + 678);
                break;
            }
        }
    }
}