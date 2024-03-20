#include <iostream>
#include <cstring>
#include <map>
#include <cctype>
#include <queue>
using namespace std;
const int N = 256;
bool vis[273][273][273];
map<char, int> st, en;
char mp[10];
char g[273][273];
int w, h, n, tot;
struct state
{
    int a[4]={0};
    int step;
};
struct edge
{
    int to;
    int nex;
} e[N * 10];
int head[N * 10], cnt=0;
void add(int u, int v)
{
    e[cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt++;
}
void init()
{
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    st.clear();
    en.clear();
    cnt = 0;
    tot = 0;
}
void graph()
{
    add(0, 0);
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            if (g[i][j] == '#')
                continue;
            if (i > 1 && g[i - 1][j] != '#')
            {
                add(i * h + j, (i - 1) * h + j);
            }
            if (j > 1 && g[i][j - 1] != '#')
            {
                add(i * h + j, i * h + j - 1);
            }
            if(i<=w-1&&g[i+1][j]!='#')
            {
                add(i*h+j,(i+1)*h+j);
            }
            if(j<=h-1&&g[i][j+1]!='#')
            {
                add(i*h+j,i*h+j+1);
            }
            add(i*h+j,i*h+j);
        }
    }
}
bool check(state &s)
{
    for (int i = 0; i < n; i++)
    {
        if (s.a[i] != en[mp[i]])
        {
            return false;
        }
    }
    return true;
}
void bfs()
{
    state s;
    for (int i = 0; i < n; i++)
    {
        s.a[i] = st[mp[i]];
    }
    s.step = 0;
    queue<state> q;
    q.push(s);
    while (!q.empty())
    {
        state u = q.front();
        q.pop();
        if (check(u))
        {
            cout << u.step << endl;
            return;
        }
        for (int i = head[u.a[0]]; ~i; i = e[i].nex)
        {
            for (int j = head[u.a[1]]; ~j; j = e[j].nex)
            {
                for (int k = head[u.a[2]]; ~k; k = e[k].nex)
                {
                    state v;
                    v.a[0] = e[i].to;
                    v.a[1] = e[j].to;
                    v.a[2] = e[k].to;
                    v.step = u.step + 1;
                    if (!vis[v.a[0]][v.a[1]][v.a[2]] && v.a[0] != v.a[1] && v.a[1] != v.a[2] && v.a[0] != v.a[2])
                    {
                        vis[v.a[0]][v.a[1]][v.a[2]] = 1;
                        q.push(v);
                    }
                }
            }
        }

    }
    cout << -1 << '\n';
}
void solve()
{
    init();
    // cin >> w >> h >> n;
    getchar();
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            scanf("%c", &g[i][j]);
            printf("%c", g[i][j]);
            if (islower(g[i][j]))
            {
                mp[tot++] = g[i][j];
                st[g[i][j]] = i * h + j;
            }
            else if (isupper(g[i][j]))
            {
                en[tolower(g[i][j])] = i * h + j;
            }
        }
        printf("\n");
        getchar();

    }
    for (int i = 0; i < n;i++){
        printf("%c %d %d\n", mp[i], st[mp[i]], en[mp[i]]);
    }
        graph();
    bfs();
}
int main()
{
    while (scanf("%d %d %d",&h,&w,&n) && w || h || n){
        printf("%d %d %d\n",h,w,n);
        solve();
    }
}