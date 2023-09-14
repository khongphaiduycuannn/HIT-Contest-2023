#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n, s;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        unsigned long long sum = n * (n + 1) / 2;
        sum -= s;
        cout << ((sum < 0 || sum > n) ? 0 : sum) << endl;
    }
    return 0;
}
