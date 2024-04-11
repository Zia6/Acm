#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> de;
int c[10000], d[10000];
string n, m;
bool check;
int t = 0;

int main()
{
    cin >> n;
    cin >> m;
    if (n[0] == '-')
        n = n.substr(1);
    if (m[0] == '-')
        m = m.substr(1);
    if (n.size() < m.size() || (n.size() == m.size() && n < m))
        swap(n, m), check = true;
    for (int i = n.size() - 1; i >= 0; i--)
        a.push_back(n[i] - '0');
    for (int j = m.size() - 1; j >= 0; j--)
        b.push_back(m[j] - '0');
    for (int i = 0; i < a.size();i++){
        cout << a[i] ;
    }
    cout << '\n';
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            c[i + j] += a[i] * a[j];
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }
    int go1 = 1000;
    while (c[go1] == 0 && go1 >= 1)
        go1--; // 确定c的长度
    for (int i = 0; i <= go1;i++){
        cout << c[go1 - i];
    }
    cout << '\n';
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            d[i + j] += b[i] * b[j];
            d[i + j + 1] += d[i + j] / 10;
            d[i + j] %= 10;
        }
        }
    for (int i = 0; i <= go1; i++)
    {
        t = t + c[i] - d[i];
        de.push_back((t + 10) % 10);
        if (t >= 0)
            t = 0;
        else
            t = -1;
    }
    while (de.back() == 0 && de.size() > 0)
        de.pop_back(); // 把前置零去掉
    if (check)
        printf("-");
    for (int i = de.size() - 1; i >= 0; i--)
        cout << de[i];
    return 0;
}