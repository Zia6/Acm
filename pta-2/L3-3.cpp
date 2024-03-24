#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N = 105;
int n, m;
int dx[8] = {1, -1, 1, -1, 1, -1, 0, 0};
int dy[8] = {0, 0, 1, 1, -1, -1, 1, -1};
int g[N][N], vis[N][N], rec[N][N];

struct vec
{
    int x, y;
    int operator^(const vec &v)
    {
        return x * v.y - y * v.x;
    }
};
struct node
{
    int x, y;
    int step;
    node(){};
    node(int x, int y, int step) : x(x), y(y), step(step){};
};
struct point{
    int x, y;
}
vector<point> v[3][N][N];
void init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void getg(int x1, int y1, int x2, int y2)
{
    if (x2 < x1)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    vec vv = {x2 - x1, y2 - y1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vec vv2 = {i - x1, j - y1};
            int tem = vv ^ vv2;
            if (tem == 0)
            {
                vis[i][j] = 1;
                continue;
            }else {
                if(tem>0){
                    rec[i][j] = 1;
                }else
                    rec[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            for (int k = 0; k < 8; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&rec[x][y]==rec[i][j]){
                    v[rec[x][y]][x][y].push_back({i, j});
                    v[rec[i][j]][i][j].push_back({x, y});
                }
            }
        }
    }
}
queue<node> q;
void bfs(){
    
}
}
void solve()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    gerg(x, y);
}
int main()
{
    init();
    solve();
}