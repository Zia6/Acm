#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
int a[4];
int main(){
    int m, t, pre, ma = -1;
    for (int i = 0; i < 4;i++){
        cin >> a[i];
        ma = max(a[i], ma);
    }
    cin >> m >> pre;
    for (int i = 0; i < 4;i++){
        if(a[i] < m || abs(a[i] - ma) > pre){
            ans.push_back(i + 1);
        }
    }
    if(ans.size() >= 2){
        cout << "Warning: please check all the tires!";
    }else if(ans.size() == 1){
        cout << "Warning: please check #" << ans[0] << "!";
    }else
        cout << "Normal";
}