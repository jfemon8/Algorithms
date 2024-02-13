#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> arr[N];
bool vis[N];
int parent[N];
bool cycle;

void dfs(int src)
{
    vis[src] = true;

    for (int i : arr[src])
    {
        if (vis[i] && parent[src] != i)
        {
            cycle = true;
        }
        if (!vis[i])
        {
            parent[i] = src;
            dfs(i);
        }
    }
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
        arr[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
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
