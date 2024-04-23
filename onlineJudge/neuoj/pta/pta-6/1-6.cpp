#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s[35];
int main()
{
    int n, m;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (j < n && (s[j].find("easy") != string::npos || s[j].find("qiandao") != string::npos))
        {
            j++;
        }
        if (j >= n)
        {
            cout << "Wo AK le";
            return 0;
        }
        j++;
    }
    if (j >= n)
    {
        cout << "Wo AK le";
        return 0;
    }else
        cout << s[j];
}