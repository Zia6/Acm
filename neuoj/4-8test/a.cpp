#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    string s;
    cin >> s;
    int i = 0;
    while(i < s.size() - 1){
        if(tolower(s[i]) == tolower(s[i + 1]) && (islower(s[i]) ^ islower(s[i + 1]))){
            s.erase(i + 1);
            s.erase(i);
            i--;
        }
        cout << s << '\n';
        i++;
    }
    cout << s << '\n';
}