#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    int n, e, src;
    cin >> n >> e;
    vector<Edge> EdgeList;
    int dis[n];
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        EdgeList.push_back(Edge(a, b, c));
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            if (dis[ed.u] < INT_MAX && dis[ed.u] + ed.c < dis[ed.v])
            {
                dis[ed.v] = dis[ed.u] + ed.c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        if (dis[ed.u] < INT_MAX && dis[ed.u] + ed.c < dis[ed.v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Negative cycle found!" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (dis[i] == INT_MAX)
            {
                cout << src << " to " << i << " -> INF " << endl;
            }
            else
            {
                cout << src << " to " << i << " -> " << dis[i] << endl;
            }
        }
    }

    return 0;
}
