#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];

void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}

int find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    return par[node] = find(par[node]);
}

void union_by_rank(int node1, int node2)
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

void union_by_size(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    int n, x;
    cin >> n;
    initialize(n);
    cin >> x;
    while (x--)
    {
        int a, b;
        cin >> a >> b;
        union_by_rank(a, b);
    }
    cout << "Node->Leader" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "   ->   " << find(i) << endl;
    }

    return 0;
}
