#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// 插入节点到BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode(value);
    if (value > root->value) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

// 层序遍历
vector<int> levelOrder(TreeNode* root, bool& isComplete) {
    vector<int> res;
    if (root == nullptr) return res;

    queue<TreeNode*> q;
    q.push(root);
    TreeNode* front;
    bool isLastLevel = false;

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            front = q.front();
            q.pop();
            res.push_back(front->value);
            
            if (front->left) {
                if (isLastLevel) isComplete = false; // 发现空节点后还有孩子，不是完全二叉树
                q.push(front->left);
            } else {
                isLastLevel = true;
            }

            if (front->right) {
                if (isLastLevel) isComplete = false; // 发现空节点后还有孩子，不是完全二叉树
                q.push(front->right);
            } else {
                isLastLevel = true;
            }
        }
    }

    return res;
}

int main() {
    int N, value;
    cin >> N;
    TreeNode* root = nullptr;

    for (int i = 0; i < N; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    bool isComplete = true;
    vector<int> traversal = levelOrder(root, isComplete);

    for (size_t i = 0; i < traversal.size(); ++i) {
        cout << traversal[i];
        if (i != traversal.size() - 1) cout << " ";
    }
    cout << endl;

    cout << (isComplete ? "YES" : "NO") << endl;

    return 0;
}
