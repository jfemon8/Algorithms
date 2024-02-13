#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> arr[N];
bool vis[N];
bool path[N];
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    path[src] = true;

    for (int i : arr[src])
    {
        if (path[i])
        {
            cycle = true;
        }
        if (!vis[i])
        {
            dfs(i);
        }
    }
    path[src] = false;
}

int main()
{
    int v, e;
    cycle = false;
    cin >> v >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }

    memset(vis, false, sizeof(vis));
    memset(path, false, sizeof(path));
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (cycle)
    {
        cout << "Cycle detected." << endl;
    }
    else
    {
        cout << "Cycle has not detected." << endl;
    }

    return 0;
}
