#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> mp, mp2;
struct node
{
    string s1, s2;
    int x;
    string t;
    int tt;
    int index;
    bool operator<(const node &n)
    {
        return tt < n.tt;
    }
};
bool cmp(node n1,node n2){
    return n1.index < n2.index;
}
int getT(string &s)
{
    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[3] - '0') * 10 + (s[4] - '0');
    return a * 60 + b;
}
bool iscard(string &s)
{
    if (s.size() != 18)
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] - '0' < 0 || s[i] - '0' > 9)
            return false;
    }
    return true;
}
vector<node> ans1, ans2, v;
int main()
{
    int D, P;
    cin >> D >> P;
    for (int k = 1; k <= D; k++)
    {
        ans1.clear();
        v.clear();
        int T, S;
        cin >> T >> S;
        for (int i = 0; i < T; i++)
        {
            string s1, s2, t;
            int x;
            cin >> s1 >> s2 >> x >> t;
            if (!iscard(s2))
                continue;

            if(mp.count(s1) && !mp2.count(s1) && x == 1){
                ans2.push_back({s1, s2, x, t, getT(t), i});
                mp2[s1] = 1;
            }
            if (!mp.count(s1) || mp[s1] + P + 1 <= k)
            {
                ans1.push_back({s1, s2, x, t, getT(t),i});
            }
        }
        sort(ans1.begin(), ans1.end());
        int l = min(S, (int)ans1.size());
        for (int i = 0; i < l; i++)
        {
            mp[ans1[i].s1] = k;
            v.push_back(ans1[i]);
            cout << ans1[i].s1 << ' ' << ans1[i].s2 << '\n';
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < l;i++){
            if (v[i].x == 1 && !mp2.count(v[i].s1))
            {
                ans2.push_back(v[i]);
                mp2[v[i].s1] = 1;
            }
        }
    }
    for (auto it : ans2)
    {
        cout << it.s1 << ' ' << it.s2 << '\n';
    }
}