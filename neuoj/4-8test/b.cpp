#include<iostream>
#include<algorithm>
using namespace std;
int getint(char c){
    if(c - '0' >= 0&& c - '0' <= 9 ){
        return c - '0';
    }else if(c - 'a' >=0 && c - 'a' <= 25){
        return 10 + c - 'a';
    }else
        return 36 + c - 'A';
}
int add(char a,char b){
    char c;
    int x, y;
    x = getint(a), y = getint(b);
    return (x + y) % 62;
}
int yu(char a,char b){
    char c;
    int x, y;
    x = getint(a), y = getint(b);
    return (x + y) / 62;
}
char getchar(int x){
    if(x <= 9){
        return x + '0';
    }else if( x < 36){
        return 'a' + x - 10;
    }else
        return 'A' + x - 36;
}
int main(){
    string s1, s2;
    string s;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int l1 = s1.size(), l2 = s2.size();
    char c;
    int yu = 0;
    for (int i = 0; i < min(l1, l2);i++){
        c = getchar((yu + getint(s1[i]) + getint(s2[i]))%62);
        yu = (yu + getint(s1[i]) + getint(s2[i])) / 62;
        s += c;
    }
    for (int i = min(l1, l2); i < max(l1, l2);i++){
        if(l1 >= i){
            c = getchar((getint(s1[i]) + yu) % 62);
            yu = (yu + getint(s1[i])) / 62;
            s += c;
        }
    }
    if(yu){
        s += "1";
    }
        reverse(s.begin(), s.end());
    cout << s << '\n';
}