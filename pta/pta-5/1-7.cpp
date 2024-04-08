#include<iostream>
using namespace std;
string s;
int main(){
    int m, n;
    cin >> m >> n;
    while(n--){
        cin >> s;
        int ans = 1, te = 1;
        for (int i = 0; i < m - 1;i++){
            if(s[i] == 'y'){
                ans = ans << 1;
            }else
                ans = ans << 1 | 1;
            te <<= 1;
        }
        ans = (ans - te) << 1 | 1;
        if(s[m - 1] == 'n'){
            ans++;
        }
        cout << ans << '\n';
    }
}