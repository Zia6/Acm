#include <iostream>
using namespace std;
int f(int x){
    int y = x;
    int cnt = 0;
    while(y){
        cnt++;
        y /= 10;
    }
    if(cnt & 1)
        return 0;
    else {
        int ans1 = 0, ans2 = 0, cnt2 = 0;
        while(x){
            cnt2++;
            if(cnt2 <= cnt / 2){
                ans1 += x % 10;
            }else
                ans2 += x % 10;
            x /= 10;
        }
        return ans1 == ans2;
    }
}
int main()
{
    int ans = 0;
    for (int i = 1; i < 100000000;i++){
        ans += f(i);
    }
    cout << ans << '\n';
}