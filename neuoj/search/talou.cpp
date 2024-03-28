#include <iostream>
#include <cstdio>
#include<map>
#include <vector>
#include <algorithm>
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
using namespace std;
int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        if(!cnt||a[cnt - 1]<=t){
            a[cnt++] = t;
        }else {
            int l = 0, r = cnt - 1;
            int mid = (l + r) >> 1;
            while(l < r){
                mid = (l + r) >> 1;
                if(a[mid]>t){
                    r = mid;
                }else
                    l = mid + 1;
            }
            a[l] = t;
        }
    }
    cout << cnt << '\n';
}