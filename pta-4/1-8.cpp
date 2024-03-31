#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
using namespace std;
vector<string> v;
string s;
string t2;
int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--)
    {

        s.clear();
        v.clear();
        t2.clear();
        getline(cin, s);
        // getchar();

        cout << s << '\n';
        cout << "AI: ";
        int _size = s.length();
        for (int i = 0; i < _size; i++)
        {
            // if(i<_size&&s[i] ==' '&&ispunct(s[i+1]) )
            //     continue;
            if (s[i] == ' ')
            {

                // if (i < _size - 1)
                // {
                //     continue;
                // }
                if (t2.size() != 0)
                    v.push_back(t2);
                t2.clear();
            }else if(ispunct(s[i])&&s[i]!=' '){
                if(s[i] == '?')
                    s[i] = '!';
                if (t2.size() != 0)
                    v.push_back(t2);
                t2.clear();
                t2 += s[i];
                v.push_back(t2);
                t2.clear();
            }
            else
            {
                if (isupper(s[i]) && s[i] != 'I')
                {
                    s[i] = tolower(s[i]);
                }
                if (s[i] == '?')
                    s[i] = '!';
                t2 += s[i];
            }
            // if(t2!=" ")
            // v.push_back(t2);
            // t2.clear();
        }
        v.push_back(t2);
        _size = v.size();
        for (int i = 0; i < _size; i++)
        {
            if (i < _size - 1)
            {
                if (v[i] == "can" && v[i + 1] == "you")
                {
                    v[i] = "I";
                    v[i + 1] = "can";
                    i++;
                    continue;
                }
                else if (v[i] == "could" && v[i + 1] == "you")
                {
                    v[i] = "I";
                    v[i + 1] = "could";
                    i++;
                    continue;
                }
            }
            if (v[i] == "I" || v[i] == "me")
            {
                v[i] = "you";
            }
        }
        for (int i = 0; i < _size; i++)
        {
            cout << v[i];
            if((i < _size - 1 && ispunct(v[i+1][0])))
                continue;
            if(ispunct(v[i][0])&&v[i][0]!='!'&&v[i][0]!='.')
                continue;
            if (i < _size - 1)
                cout << ' ';
        }
        cout << '\n';
    }
}