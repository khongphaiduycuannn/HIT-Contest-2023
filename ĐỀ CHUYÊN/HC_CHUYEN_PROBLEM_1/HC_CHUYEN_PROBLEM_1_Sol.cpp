#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define FOR(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i)
#define PR(a,n) { cerr << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cerr << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
#define debug(x) cerr << #x << " = " << x << endl
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define MASK(i)  (1LL << (i))
#define FULL(i)  (MASK(i) - 1)
#define  __builtin_popcount  __builtin_popcountll
//ifstream file("input.txt");
//#define cin file
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <class T, class T2> ostream& operator << (ostream &o, pair<T, T2> p)
{
    o << p.first << " " << p.second << "\n";
    return o;
}
template <class T> ostream& operator << (ostream &o, vector<T> vt)
{
    for (auto it: vt)
        o << it << " ";
    o << "\n";
    return o;
}
#define int long long
const int M = 2e3 + 3, mod = 1e9 + 7;
pll a[M];
int pre[M];
int res;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    FOR(i, 1, n)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i].se;
    FOR(i, 1, n)
    {
        int x = a[i].se;
        res += x * (x - 1) * (x - 2) / 6 % mod;
        res %= mod;
    }
    FOR(i, 1, n) FOR(j, 1, n)
    {
        if (j == i || 2 * a[i].fi <= a[j].fi)
            continue;
        res += a[i].se * (a[i].se - 1) / 2 * a[j].se % mod;
        res %= mod;
    }
    FOR(i, 3, n)
    {
        FOR (l, 1, i - 2)
        {
            pll p = {a[i].fi - a[l].fi, mod};
            int r = upper_bound(a + l + 1, a + i, p) - a;
            if (r < i)
            {
                res += (pre[i - 1] - pre[r - 1]) * a[i].se % mod * a[l].se % mod;
                res %= mod;
            }
        }
    }
    cout << res;
}
