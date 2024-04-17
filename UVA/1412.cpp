#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int maxn = 8;
const int maxm = 105;
map<vector<int>, int> ID;
vector<vector<int>> state;
vector<vector<int>> buy, sell;
double sale[maxn][maxm];
string name[maxn];
int high[maxn], s[maxn], n, c, m, k;
void dfs(int now, vector<int> &lots, int totlot)
{
    if (now == n)
    {
        ID[lots] = state.size();
        state.push_back(lots);
        return;
    }
    for (int i = 0; i <= high[maxn] && totlot + i <= k;i++)
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
    buy.resize((int)state.size(), vector<int>(n));
    sell.resize((int)state.size(), vector<int>(n));
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
            if (newstate[j] < high[j] && tot + 1 <= k){
                newstate[j]++;
                buy[ID[state[i]]][j] = ID[newstate];
                newstate[j]--;
            }
            if(newstate[j]){
                newstate[j]--;
                sell[ID[state[i]]][j] = ID[newstate];
                newstate[j]++;
            }
        }
    }
}

int main()
{
    cin >> c >> m >> n >> k;
    for (int i = 0; i < n;i++){
        cin >> name[i] >> s[i] >> high[i];
        for (int j = 0; j < m;j++){
            cin >> sale[i][j];
        }
    }
    init();

}