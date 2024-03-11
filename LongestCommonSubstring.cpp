#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b, ans;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int ci, cj, mx = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                ci = i;
                cj = j;
            }
        }
    }

    cout << "Length of Longest Common Substring is: " << dp[ci][cj] << endl;

    while (dp[ci][cj] != 0)
    {
        ans += a[--ci];
        cj--;
    }
    reverse(ans.begin(), ans.end());

    cout << "The Substring is: " << ans << endl;

    return 0;
}
