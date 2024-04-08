#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<char> op;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        v.clear();
        op.clear();
        string s;
        cin >> s;
        int l = s.size();
        for (int i = 0; i < l; i++)
        {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
            {
                int j = i;
                int cnt = 0;
                while (j < l &&s[j] - '0' >= 0 && s[j] - '0' <= 9){
                    cnt *= 10;
                    cnt += s[j] - '0';
                    j++;
                }
                i = j - 1;
                v.push_back(cnt);
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                int j = i + 1;
                int cnt = 0;
                while (j < l &&s[j] - '0' >= 0 && s[j] - '0' <= 9){
                    cnt *= 10;
                    cnt += s[j] - '0';
                    j++;
                }
                if (s[i] == '*')
                {
                    v[v.size() - 1] *= cnt;
                }
                else
                    v[v.size() - 1] /= cnt;
                i = j - 1;
            }
            else
            {
                op.push_back(s[i]);
            }
        }
        int ans = v[0];
        for (int i = 0; i < op.size(); i++)
        {
            if (op[i] == '+')
            {
                ans += v[i + 1];
            }
            else
                ans -= v[i + 1];
        }
        cout << ans << '\n';
    }
}