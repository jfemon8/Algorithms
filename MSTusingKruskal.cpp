#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int level[N];

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        level[i] = 0;
    }
}

int find(int node)
{
    if (par[node] == node)
    {
        return node;
    }
    return par[node] = find(par[node]);
}

void unionByRank(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderB] = leaderA;
        level[leaderA]++;
    }
}

bool cmp(Edge x, Edge y)
{
    return (x.c < y.c);
}

int main()
{
    vector<Edge> vec;
    int n, e, cost = 0;
    cin >> n >> e;
    makeSet(n);
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({a, b, c});
    }
    sort(vec.begin(), vec.end(), cmp);
    for (Edge child : vec)
    {
        int leader1 = find(child.u);
        int leader2 = find(child.v);
        if (leader1 != leader2)
        {
            unionByRank(leader1, leader2);
            cost += child.c;
        }
    }
    cout << "Minimum cost: " << cost << endl;

    return 0;
}
