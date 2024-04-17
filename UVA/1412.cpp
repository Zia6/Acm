#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;
const int maxn = 8;
const int maxm = 105;
const int maxstate = 15000;
map<vector<int>, int> ID;
vector<vector<int>> state;
int buy[maxstate][maxn], sell[maxstate][maxn];
double sale[maxn][maxm], c;
string name[maxn];
int high[maxn], s[maxn], n, m, k;
double d[maxm][maxstate];
void dfs(int now, vector<int> &lots, int totlot)
{
    if (now == n)
    {
        ID[lots] = state.size();
        state.push_back(lots);
        return;
    }
    for (int i = 0; i <= high[now] && totlot + i <= k; i++)
    {
        lots[now] = i;
        dfs(now + 1, lots, totlot + i);
    }
}
void init()
{
    ID.clear();
    state.clear();
    vector<int> lots(n);
    dfs(0, lots, 0);
    for (int i = 0; i < state.size(); i++)
    {
        vector<int> newstate = state[i];
        int tot = 0;
        for (int j = 0; j < n; j++)
        {
            tot += state[i][j];
        }
        for (int j = 0; j < n; j++)
        {
            buy[i][j] = sell[i][j] = -1;
            if (newstate[j] < high[j] && tot + 1 <= k)
            {
                newstate[j]++;
                buy[i][j] = ID[newstate];
                newstate[j]--;
            }
            if (newstate[j] > 0)
            {
                newstate[j]--;
                sell[i][j] = ID[newstate];
                newstate[j]++;
            }
        }
    }
}
double dp(int now, int id, double remain)
{
    if (now == m)
    {
        return remain;
    }
    double &ans = d[now][id];
    ans = max(ans,dp(now + 1, id, remain));
    for (int i = 0; i < n; i++)
    {
        if (buy[id][i] != -1)
        {
            if (remain >= 1.0 * s[i] * sale[i][now] - 1e-3)
            {
                ans = max(ans, dp(now + 1, buy[id][i], remain - 1.0 * s[i] * sale[i][now]));
            }
        }
        if (sell[id][i] != -1)
        {
            ans = max(ans, dp(now + 1, sell[id][i], remain + s[i] * sale[i][now]));
        }
    }
    return ans;
}
int opt[maxm][maxstate];
int pre[maxm][maxstate];
void update(int day, int s, int s2, double v, int o)
{
    if (v > d[day + 1][s2])
    {
        d[day + 1][s2] = v;
        opt[day + 1][s2] = o;
        pre[day + 1][s2] = s;
    }
}
double dp()
{
    for (int day = 0; day <= m; day++)
    {
        for (int sta = 0; sta < state.size(); sta++)
        {
            d[day][sta] = -2;
        }
    }
    d[0][0] = c;
    for (int day = 0; day < m; day++)
    {
        for (int sta = 0; sta < state.size(); sta++)
        {
            double v = d[day][sta];
            if (v < -1)
                continue;
            update(day, sta, sta, v, 0);
            for (int i = 0; i < n; i++)
            {
                if (buy[sta][i] >= 0 && v >= sale[i][day] * s[i] - 1e-3)
                {
                    update(day, sta, buy[sta][i], v - sale[i][day] * s[i], i + 1);
                }
                if (sell[sta][i] >= 0)
                {
                    update(day, sta, sell[sta][i], v + sale[i][day] * s[i], -i - 1);
                }
            }
        }
    }
    return d[m][0];
}
void print(int now,int sta){
    if(now == 0)
        return;
    print(now - 1, pre[now][sta]);
    if(opt[now][sta] > 0){
        cout << "BUY ";
    }else if(opt[now][sta] < 0){
        cout << "SELL ";
    }else {
        cout << "HOLD" << '\n';
        return;
    }
    cout << name[abs(opt[now][sta]) - 1]<< '\n';
}
int main()
{
    while(cin >> c >> m >> n >> k && m){
    for (int i = 0; i < n; i++)
    {
        cin >> name[i] >> s[i] >> high[i];
        for (int j = 0; j < m; j++)
        {
            cin >> sale[i][j];
        }
    }
    init();
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < state.size(); j++)
        {
            d[i][j] = -2;
        }
    }
    cout <<fixed << setprecision(2) <<  dp() << '\n';
    print(m, 0);
    cout << '\n';
    // cout << dp(0, 0, c);
    }
}