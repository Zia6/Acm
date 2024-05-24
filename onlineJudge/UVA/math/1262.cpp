#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

int vis[5][26];
char a[6][5], b[6][5];
vector<int> v[5];
set<int> s[5];

int main() {
    int T, k, mul = 1;
    cin >> T;
    while (T--) {
        cin >> k;
        k -= 1; // 将k调整为从0开始索引
        mul = 1;
        for (int i = 0; i < 5; i++) {
            memset(vis[i], 0, sizeof(vis[i]));
            s[i].clear(); // 使用set来存储字符
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
                vis[j][a[i][j] - 'A'] = 1;
            }
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> b[i][j];
                if (vis[j][b[i][j] - 'A']) {
                    s[j].insert(b[i][j] - 'A');
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            v[i].assign(s[i].begin(), s[i].end()); // 将set转换为vector以便排序和索引
            sort(v[i].begin(), v[i].end());
            mul *= v[i].size();
        }
        if (k >= mul || mul == 0) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < 5; i++) {
            int size = v[i].size(); // 存储当前列大小
            mul /= size;
            cout << (char)('A' + v[i][k / mul]);
            k %= mul;
        }
        cout << '\n';
    }
    return 0;
}
