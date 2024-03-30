#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int main(){
    int n, x, ans = 0;
    int l = 0, r = n - 1, rr;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n;i++){
        scanf("%d", a + i);
    }
    sort(a, a + n);
    reverse(a, a + n);
    while(l < r){
        int mid = l + ((r - l) >> 1);
        if(a[n-1] + a[mid] <= x)
            r = mid;
        else
            l = mid + 1;
    }
    l = n - 1;
    while(l < r){
        if(a[l] + a[r] <= x){
            ans++;
            l++;
            r--;
        }else {
            
        }
    }
}