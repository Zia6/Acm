#include<cstdio>
#include<set>
using namespace std;
struct seg{
    int x, y;
    bool operator < (const seg &s)const {
        return y==s.y?x < s.x:y < s.y;
    }
    bool operator == (const seg &s) const {
        return x == s.x && y == s.y;
    }
};
multiset<int> ms;
set<seg> s;
int main(){
    int x,n;
    scanf("%d %d", &x, &n);
    ms.insert(x);
    s.insert({0, x});
    for (int i = 0; i < n;i++){
        int t;
        scanf("%d", &t);
        auto it = s.upper_bound({t, t});
        // printf("%d %d ", it->x, it -> y);
        auto it2 = ms.find((it->y) - (it->x));
        ms.erase(it2);
        ms.insert((it->y) - t);
        ms.insert(t - (it->x));

        s.insert({(it->x), t});
        s.insert({t, (it->y)});
        s.erase(it);
        // for(auto j : s){
        //     printf("%d %d |", j.x, j.y);
        // }
        printf("%d ", *ms.rbegin());
    }
}