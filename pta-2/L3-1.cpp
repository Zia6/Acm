#include <iostream>
#include <map>
#include <vector>
const int N = 1e5;
using namespace std;
map<int, int> fa, le, ri, dep;
vector<int> v[N];
struct node
{
    struct node *left;
    struct node *right;
    int value;
    int dep = 0;
    struct node *fa;
};
node *root = NULL;
void insert(node *p)
{
    int x = p->value;
    if (!root)
        root = p;
    else
    {
        node *now = root;
        while (now)
        {
            if (x > now->value && now->right)
            {
                now = now->right;
            }
            else if (x < now->value && now->left)
            {
                now = now->left;
            }
            else if (x < now->value && !now->left)
            {
                now->left = p;
                p->fa = now;
                return;
            }
            else
            {
                now->right = p;
                p->fa = now;
                return;
            }
        }
    }
}
void dfs(node *now)
{
    if (now->fa)
    {
        now->dep = now->fa->dep + 1;
        fa[now->value] = now->fa->value;
    }
    dep[now->value] = now->dep;
    if (now->left)
    {
        le[now->value] = now->left->value;
        dfs(now->left);
    }
    if (now->right)
    {
        ri[now->value] = now->right->value;
        dfs(now->right);
    }
}
int main()
{
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        node *p = new (node);
        p->value = t;
        p->left = NULL;
        p->right = NULL;
        p->fa = NULL;
        p->dep = 0;
        insert(p);
    }
    dfs(root);
    int q;
    cin >> q;
    string s;
    while (q--)
    {
        int t1, t2;
        cin >> t1;
        cin >> s;
        if (s == "is")
        {
            cin >> s >> s;
            if (s == "root")
            {
                
                if (root->value == t1)
                {
                    cout << "Yes\n";
                }
                else
                    cout << "No\n";
            }
            else
            {
                if (s == "parent")
                {
                    cin >> s >> t2;
                    if (fa[t2] == t1)
                    {
                        cout << "Yes\n";
                    }
                    else
                        cout << "No\n";
                }
                else
                {
                    if (s == "left")
                    {
                        cin >> s >> s >> t2;
                        if (le[t2] == t1)
                        {
                            cout << "Yes\n";
                        }
                        else
                            cout << "No\n";
                    }
                    else
                    {
                        cin >> s >> s >> t2;
                        if (ri[t2] == t1)
                        {
                            cout << "Yes\n";
                        }
                        else
                            cout << 'No\n';
                    }
                }
            }
        }
        else
        {
            cin >> t2 >> s >> s;
            if (s == "on")
            {
                cin >> s >> s >> s;
                if (dep[t1] == dep[t2])
                {
                    cout << "Yes\n";
                }
                else
                    cout << "No\n";
            }
            else
            {
                if (fa[t1] == fa[t2])
                {
                    cout << "Yes\n";
                }
                else
                    cout << "No\n";
            }
        }
    }
}
