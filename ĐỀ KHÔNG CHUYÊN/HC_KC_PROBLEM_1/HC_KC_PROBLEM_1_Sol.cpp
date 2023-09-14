#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    string x;
    cin >> x;
    string z(x.length(), x[0]);
    if(z > x)
    {
        cout << stoll(z) - stoll(x);
    }
    else
    {
        if(z[0] < '9')
        {
            fill(z.begin(), z.end(), z[0] + 1);
            cout << stoll(z) - stoll(x);
        }
        else
        {
            cout << setfill('1') << setw(z.length()) << 2;
        }
    }
    return 0;
}
