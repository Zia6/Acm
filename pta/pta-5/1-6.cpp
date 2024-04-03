#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
vector<string> v;
int main(){
    string s;
    int cnt = 0, ans = 0, tmp = 1;
    while (getline(cin,s) && !(s.size() == 1 && s[0] == '.')){
        string t;
        v.clear();
        int l = s.length();
        for (int i = 0; i < l;i++){
            if(s[i] == ' ' || ispunct(s[i])){
                v.push_back(t);
                t.clear();
            }else
                t += s[i];
        }
        v.push_back(t);
        int si = v.size();
        for (int i = 0; i < si - 2;i++){
            if(v[i] == "chi1" && v[i+1] =="huo3" && v[i+2] == "guo1"){
                cnt++;
                if(!ans)
                    ans = tmp;
            }
        }
        tmp++;
    }
    cout << tmp - 1 << '\n';
    if(ans == 0){
        cout << "-_-#";
    }else {
        cout << ans << ' ' << cnt;
    }
}