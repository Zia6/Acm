#include<cstdio>
#include<set>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
set<int> s;
int main(){
    int n;
    scanf("%d", &n);
    int l = 0;
    for (int i = 0; i < n;i++){
        scanf("%d", a + i);
    }
    int ans = 0;
    for (int i = 0; i < n;i++){
        if(s.find(a[i])!=s.end()){
            while(a[l]!=a[i]){
                s.erase(a[l]);
                l++;
            }
            l++;
            ans = max((int)s.size(), ans);
        }else {
            s.insert(a[i]);
        }
        ans = max((int)s.size(), ans);
    }

    printf("%d", ans);
}