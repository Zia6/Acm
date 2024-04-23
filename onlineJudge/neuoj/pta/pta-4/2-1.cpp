#include<iostream>
#include<set>
using namespace std;
const int N = 1e4 + 5;
int vis[N], prime[N], vvis[N];
int cnt[N];
set<int> ans;
void euler(){
    int cnt = 0;
    vis[1] = 1;
    for (int i = 2; i < N;i++){
        if(!vis[i]){
            prime[cnt++] = i;
        }
        int j = 0;
        while (j < cnt && prime[j] * i <= N)
        {
            vis[prime[j] * i] = 1;
            if(i%prime[j] == 0)
                break;
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
void check(int x){
    if(vvis[x])
        return;
    int num = x;
    set<int> diff;
    diff.insert(x);
    vvis[x] = true;
    while(x!=1){
        x = nex(x);
        if(diff.count(x))
            return;
        if(ans.count(x))
            ans.erase(x);
        diff.insert(x);
        vvis[x] = true;
    }
    ans.insert(num);
    cnt[num] = (int)diff.size() - 1;
}
int main(){
    euler();
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        check(i);
    }
    for(int in:ans){
        printf("%d ", in);
        if(vis[in])
            printf("%d\n", cnt[in]);
        else
            printf("%d\n", cnt[in] << 1);
    }
    if(ans.empty())
        printf("SAD\n");

    return 0;
}