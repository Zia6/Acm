#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 5;
struct movie{
    int st, en;
    bool operator < (const movie &m)const {
        return en < m.en;
    }
}mo[maxn];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d %d", &mo[i].st, &mo[i].en);
    }
    sort(mo, mo + n);
    int now = 0, ans = 0;
    for (int i = 0; i < n;i++){
        if(mo[i].st >= now){
            ans++;
            now = mo[i].en;
        }
    }
    printf("%d", ans);
}