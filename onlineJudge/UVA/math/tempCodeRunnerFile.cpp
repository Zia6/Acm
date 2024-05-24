#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int vis[5][26];
char a[6][5], b[6][5];
vector<int> v[5], ans;
int main()
{
    int T, k, mul = 1;
    cin >> T;
    while (T--)
    {
        cin >> k;
        k -= 1;
        mul = 1;
        for (int i = 0; i < 5;i++){
            memset(vis[i], 0, sizeof(vis));
            v[i].clear();
        }
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    cin >> a[i][j];
                    vis[j][a[i][j] - 'A'] = 1;
                }
            }
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> b[i][j];
                if (vis[j][b[i][j] - 'A'])
                {
                    v[j].push_back(b[i][j] - 'A');
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            sort(v[i].begin(), v[i].end());
            // for (int j = 0; j < v[i].size(); j++)
            // {
            //     cout << v[i][j] << ' ';
            // }
            // cout << '\n';
            mul *= v[i].size();
        }
        if(k >= mul || mul == 0){
            cout << "NO" << '\n';
            continue;
        }
        for (int i = 0; i < 5;i++){
            mul /= v[i].size();
            cout << (char)('A' + v[i][k / mul]);
            k = k % mul;
        }
        cout << '\n';
    }
}