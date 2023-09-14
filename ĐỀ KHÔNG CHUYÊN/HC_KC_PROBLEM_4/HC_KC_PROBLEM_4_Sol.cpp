#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m], c[n + m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    int i = 0, j = m - 1, k = 0;
    while (i < n || j >= 0)
    {
        if (i >= n)
            c[k++] = b[j--];
        else if (j < 0)
            c[k++] = a[i++];
        else if (a[i] <= b[j])
            c[k++] = a[i++];
        else if (a[i] > b[j])
            c[k++] = b[j--];
    }
    for (int i = 0; i < k; i++)
        cout << c[i] << " ";
    return 0;
}
