#include<cstdio>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 5;
struct node{
    int x;
    int index;
    bool operator < (const node &n)const {
        return x < n.x;
    }
};
struct peo{
    int x, y, index;
    bool operator < (const peo &n)const {
        return x < n.x;
    }
}no[maxn];
multiset<node> q;
int ans[maxn];
int main(){
    int n, a, b;
    int cnt = 1;
    q.insert({0, 1});
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d %d", &a, &b);
        no[i].x = a, no[i].y = b;
        no[i].index = i;
    }
    sort(no, no + n);
    for (int i = 0; i < n;i++){
        int index = no[i].index;
        a = no[i].x, b = no[i].y;
        auto it = q.lower_bound({a, a});
        if(it == q.begin()){
            ans[index] = ++cnt;
            q.insert({b, cnt});
        }else {
            it--;
            node tem = *it;
            tem.x = b;
            ans[index] = it->index;
            q.erase(it);
            q.insert(tem);
 
        }
    }
        printf("%d\n", cnt);
    for (int i = 0; i < n;i++){
        printf("%d", ans[i]);
        if(i < n - 1)
            printf(" ");
    }
}