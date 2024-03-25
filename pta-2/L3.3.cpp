#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include<cmath>
using namespace std;
const int maxs = 105, maxn = 1e4 + 100;
int dx[] = {1, -1, 1, -1, 1, -1, 0, 0};
int dy[] = {0, 0, 1, 1, -1, -1, 1, -1};
int s, e, n, m;
int g[maxs][maxs];
double dis[maxn];
bool vis[maxs][maxs];
int x[maxn], y[maxn], id[maxs][maxs];
struct node{
    int id;
    double dis;
    bool operator <(const node& n)const {
        return dis > n.dis;
    } 
};
struct vec
{
    int x;
    int y;
    int operator ^ (const vec &v)const 
    {
        return x * v.y - y * v.x;
    }
};
int f(int id1,int id2, int t)
{
    vec v1 = {x[id1] - x[s], y[id1] - y[s]}, v2 = {x[e] - x[s], y[e] - y[s]}, v3 = {x[id2] - x[s], y[id2] - y[s]};
    if(t==0){
        return (v1 ^ v2) <=0  && (v3 ^ v2) < 0;
    }else
        return (v1 ^ v2) >=0  && (v3 ^ v2) > 0;
}
void bfs()
{
    double ans = 0;
    for (int i = 0; i < 2; i++)
    {
        printf("%d\n", i);
        memset(vis, 0, sizeof(vis));
        for (int k = 0; k < maxn;k++)
            dis[k] = 1e9 + 5;
        dis[s] = 0;
        priority_queue<node> q;
        while(!q.empty()){
            q.pop();
        }
        q.push({s,0});
        while (!q.empty())
        {
            node now = q.top();
            printf("%d %d %d\n", now.id,x[now.id],y[now.id]);
            q.pop();
            vis[x[now.id]][y[now.id]] = true;
            for (int j = 0; j < 8; j++)
            {
                int nx = x[now.id] + dx[j], ny = y[now.id] + dy[j];
                // printf("%d %d\n", nx, ny);
                if (nx >= 0 && ny >= 0 && nx < n && ny < m&&!vis[nx][ny]&&(f(now.id,id[nx][ny],i)||id[nx][ny]==e)){
                    double nexdis = dis[now.id] + sqrt(dx[j] * dx[j] + dy[j] * dy[j]) * (g[nx][ny] + g[x[now.id]][y[now.id]]);
                    if(nexdis<dis[id[nx][ny]]){
                        dis[id[nx][ny]] = nexdis;
                        q.push({id[nx][ny], nexdis});
                    }
                }
            }
        }
        ans += dis[e];
    }
    printf("%f\n", ans - g[x[s]][y[s]] - g[x[e]][y[e]]);
}
int main()
{
    scanf("%d %d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            id[i][j] = cnt, x[cnt] = i, y[cnt] = j;
            scanf("%d", &g[i][j]);
            dis[cnt] = 1e9 + 5;
            cnt++;
        }
    }
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    s = id[x1][y1], e = id[x2][y2];
    if(x1>x2)
        swap(s, e);
    dis[s] = 0;
    bfs();
}
