#include <bits/stdc++.h>
using namespace std;

vector<int> arr[1001];
bool vis[1001];

void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    for (int child : arr[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int src;
    cin >> src;
    dfs(src);

    return 0;
}
