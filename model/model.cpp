#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <sstream>
template <class T>
bool lexicographicallySmaller(const std::vector<T> &a, const std::vector<T> &b)
{
    int n = a.size();
    int m = b.size();
    for (int i = 0; i < n && i < m; i++)
    {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
    }
    return (i == n & i < m);
}


template <class T>
inline void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= f;
}

int main()
{
    return 0;
}