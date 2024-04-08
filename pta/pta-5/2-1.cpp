#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    stack<int> S1;
    stack<char> S2;
    
    // 读取并存储数字
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        S1.push(number);
    }
    
    // 读取并存储运算符
    for (int i = 1; i < N; ++i) {
        char op;
        cin >> op;
        S2.push(op);
    }
    
    // 执行计算
    while (!S2.empty()) {
        int n1 = S1.top();
        S1.pop();
        int n2 = S1.top();
        S1.pop();
        char op = S2.top();
        S2.pop();
        
        int result;
        switch (op) {
            case '+':
                result = n2 + n1;
                break;
            case '-':
                result = n2 - n1;
                break;
            case '*':
                result = n2 * n1;
                break;
            case '/':
                if (n1 == 0) {
                    cout << "ERROR: " << n2 << "/0" << endl;
                    return 0;
                }
                result = n2 / n1;
                break;
            default:
                // 不应该到达这里
                return 0;
        }
        S1.push(result);
    }
    
    // 输出最终结果
    if (!S1.empty()) {
        cout << S1.top() << endl;
    }
    
    return 0;
}
