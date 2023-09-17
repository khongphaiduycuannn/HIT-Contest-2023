#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const ll base = 313;
const ll maxN = 6e3;

ll Hash[maxN], HashR[maxN], Pow[maxN];
int pref[maxN][maxN];
string s;

ll get(ll l, ll r) {
    return (Hash[r] - Hash[l]*Pow[r - l]%mod + mod)%mod;
}

ll getR(ll l, ll r) {
    return (HashR[l] - HashR[r]*Pow[r - l]%mod + mod)%mod;
}

void init() {
    Pow[0] = 1;
    for (ll i = 1; i < maxN; i++)
        Pow[i] = Pow[i - 1]*base %mod;

    ll n = s.size() - 1;
    for (ll i = 1; i <= n; i++)
        Hash[i] = (Hash[i - 1]*base%mod + s[i])%mod;
    for (ll i = n; i >= 1; i--)
        HashR[i] = (HashR[i + 1]*base%mod + s[i])%mod;

    for (ll i = 1; i <= n; i++)
        for (ll j = i; j <= n; j++) {
            if (get(i, j) == getR(i, j))
                pref[i][j] = pref[i][j - 1] + 1;
            else pref[i][j] = pref[i][j - 1];
        }

    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            pref[i][j] += pref[i - 1][j];
}

void solve(){
    cin >> s;
    s = ' ' + s;
    ll q; cin >> q;

    init();
    while(q--) {
        ll l, r;
        cin >> l >> r;
        cout << pref[r][r] - pref[l - 1][r] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}
