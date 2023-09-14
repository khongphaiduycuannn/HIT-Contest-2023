#include <bits/stdc++.h>

using namespace std;
#define int long long
int n,t,t2;
string s;
int64_t ans;
int Hash[5005];
int Hash1[5005];
int Pow[5005];
int base = 311;
int mod = 1e9 + 7;
int getHash(int i, int j)
{
    return (Hash[j] - (i - 1 >= 0?Hash[i - 1] * Pow[j - i + 1] : 0) + mod * mod) % mod;
}
int getHash1(int i, int j)
{
    return (Hash1[i] - (j + 1 < n?Hash1[j + 1] *Pow[j - i + 1] : 0 ) + mod * mod)% mod;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n=s.size();
    Pow[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        Pow[i] = Pow[i - 1] * base % mod;
    }
    Hash[0] = (s[0] - 'a' + 1) % mod;
    Hash1[n - 1] = (s[n - 1] - 'a' + 1) % mod;
    for (int i = 1; i < n; i++)
    {
        Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % mod;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        Hash1[i] = (Hash1[i + 1] * base + s[i] - 'a' + 1) % mod;
    }
    vector<vector<int>>ans(n+5, vector<int>(n + 5, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + i < n; j++)
        {
            if (i == 0)
            {
                ans[j][j] = 1;
            }
            else
            {

                ans[j][j + i] = ans[j + 1][j + i] + ans[j][j + i - 1] + (getHash(j, j + i) == getHash1(j, j +i)) - (j + 1 <= j + i - 1?ans[j +1][j + i - 1]:0);

            }
        }

    }
    int m = 0;
    cin >> m;
    for(int i=0; i<m; ++i)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << ans[l][r] << '\n';
    }
    //    Times;
}
