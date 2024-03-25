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
                    double nexdis = dis[now.id] + s