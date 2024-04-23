#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e4 + 5;
struct node{
    int value;
    string s;
    bool operator < (const node&n) const {
        return value==n.value?s>n.s:value < n.value;
    }
}a[N];
int main(){
    long long ans = 0;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i].s >> a[i].value;
        if(a[i].value>=m){
            ans += 50;
        }
        else if (a[i].value>=60)
            ans += 20;
    }
    sort(a, a + n);
    reverse(a, a + n);
    cout << ans << '\n';
    int cnt = 1;
    for (int i = 0, cnt = 1; i<n&&cnt <= k;cnt++)
    {
        int j = i;
        while(a[j].value==a[i].value){
            cout << cnt << ' ' << a[j].s << ' ' << a[j].value << '\n';
            j++;
        }
        cnt += (j - i - 1);
        i = j;
    }
}