#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> g[maxn];
int la[maxn];
int main()
{
    int n, m;
    int M;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {

        cin >> M;
        g[i].resize(M + 1);
        for (int j = 1; j <= M; j++)
        {
            cin >> g[i][j];
        }
    }
    int now = 1;
    while(m--){
        int op, to;
        cin >> op >> to;
        if(op == 0){
            now = g[now][to];
        }else if(op == 1){
            la[to] = now;
            cout << now << '\n';
        }else {
            now = la[to];
        }
    }
    cout << now;
}