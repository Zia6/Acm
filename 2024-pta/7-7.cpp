#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double H, W;
    for (int i = 0; i < n; i++)
    {
        cin >> H >> W;
        double t = (H - 100) * 0.9 * 2;
        if (W >= 1.1 * t)
        {
            cout << "You are tai pang le!" << endl;
        }
        else
        {
            if (W <= 0.9 * t)
            {
                cout << "You are tai shou le!" << endl;
            }
            else
            {
                cout << "You are wan mei!" << endl;
            }
        }
    }
}