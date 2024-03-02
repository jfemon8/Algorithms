#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 5;
ll dp[N];

ll fibo(ll n)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    ll n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl;

    return 0;
}
