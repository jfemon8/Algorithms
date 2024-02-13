#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> arr[N];
bool vis[N];
int parent[N];
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : arr[par])
        {
            if (vis[child] && parent[par] != child)
            {
                cycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
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
            bfs(i);
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
