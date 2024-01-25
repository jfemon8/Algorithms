#include <bits/stdc++.h>
using namespace std;

vector<int> v[1000];
bool vis[1000];
int level[1000];
int parent[1000];

void bfsTraversal(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << " ";

        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

void printLevel(int n)
{
    cout << endl
         << "Node -> Level" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "   ->   " << level[i] << endl;
    }
    cout << endl;
}

void shortesPath(int src, int des)
{
    vector<int> path;
    while (des > -1)
    {
        path.push_back(des);
        des = parent[des];
    }
    while (!path.empty())
    {
        cout << path.back() << " ";
        path.pop_back();
    }
    cout << endl;
}

int main()
{
    int n, e, src, des;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> src >> des;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfsTraversal(src);
    printLevel(n);
    shortesPath(src, des);

    return 0;
}
