#include <iostream>
#include <vector>
#include<set>
using namespace std;
const int N = 505;
vector<int> v[N];
set<int> se;
int color[N];
int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    int st, en;
    for (int i = 0; i < m; i++)
    {
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);
    }
    int q;
    cin >> q;
    while (q--)
    {
        for (int i = 1; i <= n; i++)
        {
            cin>>color[i];
            se.insert(color[i]);
        }
        if(se.size()!=k) {
            cout<<"No\n";
            se.clear();
            continue;
        }
        se.clear();
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(flag) break;
            int si=v[i].size();
            for(int j=0;j<si;j++){
                if(color[v[i][j]]==color[i]){
                    flag=true;
                    break;
                }
            }
        }
        if(flag) cout<<"No"<<'\n';
        else cout<<"Yes"<<'\n';
    }
}