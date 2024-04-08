#include <iostream>
#include <cstring>
using namespace std;
int a[105];
int main()
{
    for (int i = 0; i < 105; i++)
    {
        a[i] = -1e9 - 5;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if(t >= a[0]){
            a[0] = t;
            continue;
        }
        int l = 0, r = 104;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(a[mid] >= t)
                l = mid;
            else
                r = mid - 1;
        }
        a[l + 1] = max(t, a[l + 1]);
    }
    for (int i = 0; i <= n;i++){
        if(a[i] == -(1e9 +5)){
            cout << i - 1 << '\n';
            break;
            }
    }
}