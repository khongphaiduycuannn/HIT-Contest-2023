#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, Min, Max;
    cin >> n >> Min >> x;
    Max = x - Min;
    Min = min(Min, x);
    for(int i = 2; i < n; ++i)
    {
        cin >> x;
        Max = max(Max, x - Min);
        Min = min(Min, x);
    }
    cout << Max;
    return 0;
}
