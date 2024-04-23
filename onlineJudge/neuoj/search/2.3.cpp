#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
struct node{
    int index;
    int value;
    bool operator < (const node& n) const {
        return value < n.value;
    }
};
bool cmp(node n1,node n2){
    return n1.value < n2.value;
}
vector<node> v;
bool vis[N];
int a[N];
int main()
{
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a + i);
        vis[i] = false;
    }
    sort(a, a + n);
    for (int i = 0; i < n;i++){
        v.push_back({a[i], i});
    }
        for (int i = n - 1; i >= 0; i--)
        {
            if (vis[i])
                continue;
            vis[i] = true;
            v.pop_back();
            node no = {m - a[i], 0};
        }
}
