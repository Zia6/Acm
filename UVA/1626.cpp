#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 1e3 + 5;
string s;
int d[maxn][maxn];
bool match(char c1, char c2)
{
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']');
}
// d[i][j] == d[i + 1][j - 1]
// d[i][j] = d[i][k] + d[k + 1][j]
void print(int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        if (s[l] == '(' || s[r] == ')')
        {
            cout << "()";
        }
        else
            cout << "[]";
        return;
    }
    if (match(s[l], s[r]) && d[l][r] == d[l + 1][r - 1])
    {
        cout << s[l];
        print(l + 1, r - 1);
        cout << s[r];
        return;
    }
    for (int k = l; k < r; k++)
    {
        if (d[l][r] == d[l][k] + d[k + 1][r])
        {
            print(l, k);
            print(k + 1, r);
            return;
        }
    }
}
int main()
{
    int T;
    getline(cin, s);
    scanf("%d", &T);
    getchar();
    getline(cin, s);
    while (T--)
    {
        getline(cin,s);
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            d[i][i] = 1;
            d[i + 1][i] = 0;
        }
        for (int i = l - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < l; j++)
            {
                d[i][j] = l;
                if (match(s[i], s[j]))
                {
                    d[i][j] = min(d[i][j], d[i + 1][j - 1]);
                }
                for (int k = i; k < j; k++)
                {
                    d[i][j] = min(d[i][k] + d[k + 1][j], d[i][j]);
                }
            }
        }
        print(0, l - 1);
        cout << '\n';
        if(T)
            cout << '\n';
        getline(cin, s);
    }
}