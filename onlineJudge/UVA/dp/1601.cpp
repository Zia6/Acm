#include <iostream>
#include <cstring>
#include <map>
#include <cctype>
#include <queue>
using namespace std;
const int N = 256;
long long vis1[280][280][280];
long long vis2[280][280][280];
map<char, int> st, en;
char mp[10];
char g[280][280];
int w, h, n, tot;
struct state
{
    int a[4] = {0};
    long long step;
};
struct edge
{
    int to;
    int nex;
} e[N * 10];
int head[N * 10], cnt = 0;
void add(int u, int v)
{
    e[cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt++;
}
void init()
{
    memset(head, -1, sizeof(head));
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    st.clear();
    en.clear();
    memset(mp, 0, sizeof(mp));
    memset(g, 0, sizeof(g));
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
            if (i <= w - 1 && g[i + 1][j] != '#')
            {
                add(i * h + j, (i + 1) * h + j);
            }
            if (j <= h - 1 && g[i][j + 1] != '#')
            {
                add(i * h + j, i * h + j + 1);
            }
            add(i * h + j, i * h + j);
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
bool walk(state &s, state &u)
{
    if (s.a[1] == 0 && s.a[2] == 0)
    {
        return true;
    }
    if (s.a[0] == u.a[1] && s.a[1] == u.a[0])
    {
        return false;
    }
    else if (s.a[0] == u.a[2] && s.a[2] == u.a[0])
    {
        return false;
    }
    else if (s.a[1] == u.a[2] && s.a[2] == u.a[1])
    {
        return false;
    }
    else if (s.a[0] == u.a[1] && s.a[1] == u.a[0])
    {
        return false;
    }
    else if (u.a[0] == u.a[1] || u.a[0] == u.a[2] || u.a[1] == u.a[2])
    {
        return false;
    }
    return true;
}
queue<state> q1;
queue<state> q2;
void bfs()
{
    state s;
    state ee;
    for (int i = 0; i < n; i++)
    {
        s.a[i] = st[mp[i]];
        ee.a[i] = en[mp[i]];
    }
    s.step = 0;
    ee.step = 0;
    q1.push(s);
    q2.push(ee);
    vis2[ee.a[0]][ee.a[1]][ee.a[2]] = 1;
    vis1[s.a[0]][s.a[1]][s.a[2]] = 1;
    int d1 = 0, d2 = 0;
    while (!q1.empty() || !q2.empty())
    {
        while (!q1.empty())
        {
            state u = q1.front();
            if(u.step>d1){
                d1++;
                break;
            }
            // cout<<u.a[0]<<' '<<u.a[1]<<' '<<u.a[2]<<' '<<u.step<<'\n';
            q1.pop();
            // if (vis2[u.a[0]][u.a[1]][u.a[2]]>0&&vis1[u.a[0]][u.a[1]][u.a[2]]>0)
            // {
            //     // cout<<u.a[0]<<' '<<u.a[1]<<' '<<u.a[2]<<' '<<u.step<<'\n';
            //     // cout << vis1[u.a[0]][u.a[1]][u.a[2]] << '\n';
            //     cout << vis1[u.a[0]][u.a[1]][u.a[2]]+vis2[u.a[0]][u.a[1]][u.a[2]] << '\n';
            //     return;
            // }
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
                        if (walk(u, v))
                        {
                            if (!vis1[v.a[0]][v.a[1]][v.a[2]])
                            {

                                vis1[v.a[0]][v.a[1]][v.a[2]] = v.step;
                                if (vis2[v.a[0]][v.a[1]][v.a[2]])
                                {
                                    // cout << 1 << ' ';
                                    // cout<<v.a[0]<<' '<<v.a[1]<<' '<<v.a[2]<<' '<<v.step<<'\n';
                                    cout << vis2[v.a[0]][v.a[1]][v.a[2]] + vis1[v.a[0]][v.a[1]][v.a[2]] << '\n';
                                    return;
                                }
                                q1.push(v);
                                // cout << '1' << ' ';
                                // cout<<v.a[0]<<' '<<v.a[1]<<' '<<v.a[2]<<' '<<v.step<<'\n';
                            }

                            // cout << '0' << ' ';
                            // cout<<v.a[0]<<' '<<v.a[1]<<' '<<v.a[2]<<' '<<vis1[v.a[0]][v.a[1]][v.a[2]]<<'\n';
                        }
                    }
                }
            }
        }
        while (!q2.empty())
        {
            state u = q2.front();
            // cout<<u.a[0]<<' '<<u.a[1]<<' '<<u.a[2]<<' '<<u.step<<'\n';
            if(u.step>d2){
                d2++;
                break;
            }
            q2.pop();
            // if ((vis1[u.a[0]][u.a[1]][u.a[2]] > 0) && (vis2[u.a[0]][u.a[1]][u.a[2]] > 0))
            // {
            //     // cout << vis2[u.a[0]][u.a[1]][u.a[2]] << '\n';
            //     cout << vis1[u.a[0]][u.a[1]][u.a[2]] + vis2[u.a[0]][u.a[1]][u.a[2]] << '\n';
            //     return;
            // }

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
                        if (walk(u, v))
                        {

                            if (!vis2[v.a[0]][v.a[1]][v.a[2]])
                            {
                                vis2[v.a[0]][v.a[1]][v.a[2]] = v.step;
                                if (vis1[v.a[0]][v.a[1]][v.a[2]])
                                {
                                    // cout << '2' << ' ';
                                    // cout<<v.a[0]<<' '<<v.a[1]<<' '<<v.a[2]<<' '<<v.step<<'\n';
                                    cout << vis1[v.a[0]][v.a[1]][v.a[2]] + vis2[v.a[0]][v.a[1]][v.a[2]]  << '\n';
                                    return;
                                }
                                q2.push(v);
                                // cout<<'2'<<' ';
                                // cout<<v.a[0]<<' '<<v.a[1]<<' '<<v.a[2]<<' '<<v.step<<'\n';
                            }

                            // cout << 1 << ' ';

                            // cout<<v.a[0]<<' '<<v.a[1]<<' '<<v.a[2]<<' '<<vis2[v.a[0]][v.a[1]][v.a[2]]<<'\n';
                        }
                    }
                }
            }
        }
    }
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
            // printf("%c", g[i][j]);
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
        // printf("\n");
        getchar();
    }
    // for (int i = 0; i < n;i++){
    //     printf("%c %d %d\n", mp[i], st[mp[i]], en[mp[i]]);
    // }
    graph();
    bfs();
    while (!q1.empty())
    {
        q1.pop();
    }
    while (!q2.empty())
    {
        q2.pop();
    }
    return;
}
int main()
{
    while (scanf("%d %d %d", &h, &w, &n) && w || h || n)
    {
        // printf("%d %d %d\n",h,w,n);
        solve();
    }
}