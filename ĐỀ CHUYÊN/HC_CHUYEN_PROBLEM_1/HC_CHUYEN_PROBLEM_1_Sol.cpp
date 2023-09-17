#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const ll maxN = 1e5;

ll fac[maxN + 2];
ll pre[maxN + 2];

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.first < y.first;
}

ll binPow(ll a, ll x) {
    if (x == 0)
        return 1;

    ll tmp = binPow(a, x/2);
    if (x % 2)
        return tmp*tmp%mod*a%mod;
    return tmp*tmp%mod;
}

ll C(ll k, ll n) {
    if (k > n)
        return 0;

    ll t = fac[n];
    ll m = fac[k]*fac[n - k]%mod;
    return t*binPow(m, mod - 2)%mod;
}

void init() {
    fac[0] = 1;
    for (ll i = 1; i <= maxN; i++)
        fac[i] = fac[i - 1]*i%mod;
}

void solve(){
    ll t; cin >> t;
    vector<pair<ll, ll>> a(t);
    for (auto &x : a)
        cin >> x.first >> x.second;

    init();
    sort(a.begin(), a.end(), cmp);

    pre[0] = a[0].second;
    for (ll i = 1; i < t; i++)
        pre[i] += pre[i - 1] + a[i].second;

    ll res = 0;
    for (ll i = 0; i < t; i++) {
        res = (res + C(3, a[i].second)%mod)%mod;

        for (ll j = 0; j < t; j++)
            if (i != j && a[j].first < 2*a[i].first)
                res = (res + C(2, a[i].second)*a[j].second%mod)%mod;

        for (ll j = i + 1; j < t; j++) {
            ll l = j + 1, r = t - 1;
            while(l < r) {
                ll m = l + (r - l + 1)/2;
                if (a[m].first < a[i].first + a[j].first)
                    l = m;
                else r = m - 1;
            }

            if (l == r && a[l].first < a[i].first + a[j].first)
                res = (res + a[i].second*a[j].second%mod*((pre[l] - pre[j] + mod)%mod)%mod)%mod;
        }
    }

    cout << res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}
