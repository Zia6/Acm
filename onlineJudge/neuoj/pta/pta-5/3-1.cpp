#include <iostream>
#include <vector>
using namespace std;
#define int long long
vector<vector<int>> adj; // 邻接表
vector<bool> visited; // 访问标记
int paths = 0; // 路径数量
int A, B; // 起点和终点

int dfs(int node) {
    int ans = 0;
    if (node == B) {
        paths++;  // 如果到达终点 // 路径数量加一
        return 1; // 回溯
    }
    visited[node] = true; // 标记当前节点为已访问
    for (int next : adj[node]) { // 遍历所有可达节点
        if (!visited[next]) { // 如果未访问
            if(dfs(next)){
                ans = 1;
            } // 递归访问
        }
    }
    visited[node] = false; // 回溯前取消访问标记
    return ans;
}

signed main() {
    int N, M;
    cin >> N >> M;
    adj.resize(N + 1);
    visited.resize(N + 1, false);

    // 读入推理关系
    for (int i = 0; i < M; ++i) {
        int S1, S2;
        cin >> S1 >> S2;
        adj[S1].push_back(S2); // 构建邻接表
    }

    cin >> A >> B;

    int ans = dfs(A); // 从 A 开始深度优先搜索

    cout << paths << " "; // 输出路径数量
    if(ans)
        cout << "Yes";
    else
        cout << 'No';

    return 0;
}
