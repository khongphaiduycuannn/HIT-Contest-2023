#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

using type = ll;

const ll mod = 1e9 + 7;

struct Matrix {
    vector <vector <type> > data;

    int row() const { return data.size(); }

    int col() const { return data[0].size(); }

    auto & operator [] (int i) { return data[i]; }

    const auto & operator[] (int i) const { return data[i]; }

    Matrix() = default;

    Matrix(int r, int c): data(r, vector <type> (c)) { }

    Matrix(const vector <vector <type> > &d): data(d) { }

    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto x : d.data) {
            for (auto y : x) out << y << ' ';
            out << '\n';
        }
        return out;
    }

    static Matrix identity(long long n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        Matrix a = *this;
        assert(a.col() == b.row());
        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int j = 0; j < b.col(); ++j)
                for (int k = 0; k < a.col(); ++k){
                    c[i][j] += 1ll * a[i][k] % mod * (b[k][j] % mod) % mod;
                    c[i][j] %= mod;
                }
        return c;
    }

    Matrix pow(long long exp) {
        assert(row() == col());
        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};

void solve(){
    ll n; cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }

    vector<vector<ll>> start = {{1, 1}, {0, 0}};
    vector<vector<ll>> base = {{0, 1}, {1, 1}};

    Matrix mtxStart = start;
    Matrix mtxBase = base;

    Matrix res = mtxStart * mtxBase.pow(n - 2);
    cout << res[0][1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}
