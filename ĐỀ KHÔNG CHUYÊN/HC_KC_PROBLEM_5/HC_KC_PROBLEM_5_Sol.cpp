#include <bits/stdc++.h>
using namespace std;

bool laNamNhuan(int nYear)
{
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
        return true;
    return false;
}

int tinhSoNgayTrongThang(int nMonth, int nYear)
{
    int nNumOfDays;

    switch (nMonth)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        nNumOfDays = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        nNumOfDays = 30;
        break;
    case 2:
        if (laNamNhuan(nYear))
        {
            nNumOfDays = 29;
        }
        else
        {
            nNumOfDays = 28;
        }
        break;
    }

    return nNumOfDays;
}

bool laNgayHopLe(int nDay, int nMonth, int nYear)
{
    if (nYear < 0)
        return false;

    if (nMonth < 1 || nMonth > 12)
        return false;

    if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
        return false;

    return true;
}

int main()
{
    int d, m, y;
    char c;
    cin >> d >> c >> m >> c >> y;
    int n = d + m + y;
    if (laNgayHopLe(d, m, y) && n % 2 == 0)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 2; j <= 10 && i - j >= 0; j += 2)
                (dp[i] += dp[i - j]) %= 1000000007;
        cout << dp[n];
    }
    else
    {
        cout << 0;
    }
}