#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
struct seg{
    int x, y;
    bool operator < (const seg&s) const{
        return x < s.x;
    }
}s[maxn];
int main(){
    int n, m, k;
    int ans = 0;
    scanf("%d %d %d", &n,&m,&k);
    for (int i = 0; i < n;i++){
        scanf("%d", a + i);
    }
    for (int i = 0; i < m;i++){
        int t;
        scanf("%d", &t);
        s[i].x = t - k;
        s[i].y = t + k;
    }
    sort(a, a + n);
    sort(s, s + m);
    int i = 0, j = 0;
    for (j = 0; j < m;j++){
        while(i<n&&a[i]<s[j].x){
            i++;
        }
        if(i>=n)
            break;
        if(a[i]<=s[j].y){
            ans++;
            i++;
        }
    }
    printf("%d", ans);
}