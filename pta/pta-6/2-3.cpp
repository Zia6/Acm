#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;
const int maxn = 105;
int n, m;
map<vector<int>, int> mp;
struct node
{
    vector<int> a;
    int cnt;
    bool operator < (const node &t)
    {
        if (cnt == t.cnt)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == t.a[i])
                    continue;
                else
                    return a[i] > t.a[i];
            }
            return cnt < t.cnt;
        }
        else
            return cnt < t.cnt;
    }
    bool operator == (const node &t)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] != t.a[i])
                return false;
        }

        return true;
    }
};
vector<node> v;
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        node no;
        no.a.resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> no.a[j];
        }
        no.cnt = 1;
        if(mp.count(no.a) > 0){
            mp[no.a]++;
        }else {
            v.push_back(no);
            mp.insert({no.a, 1});
        }
    }
    for(auto& it:v){
        it.cnt = mp[it.a];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    cout << (int)v.size() << '\n';
    for(auto it:v){
        cout << it.cnt << ' ';
        for (int i = 0; i < n;i++){
            cout << it.a[i];
            if(i < n - 1){
                cout << ' ';
            }
        }
        cout << '\n';
    }
}