#include <iostream>
#include<cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxs = 105, maxn = 1e4 + 100;
int dx[] = {1, -1, 1, -1, 1, -1, 0, 0};
int dy[] = {0, 0, 1, 1, -1, -1, 1, -1};
int s, e, n, m;
int x[maxn], y[maxn], id[maxs];
struct vec
{
    int x;
    int y;
    int operator^(const vec &v)
    {
        return x * v.y - y * v.x;
    }
};
int main(){
    int n;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m; j++){
            
        }
    }
}
