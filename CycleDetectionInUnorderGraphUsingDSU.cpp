#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int groupSize[N];

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        groupSize[i] = 1;
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

void unionBySize(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if (groupSize[leaderA] > groupSize[leaderB])
    {
        par[leaderB] = leaderA;
        groupSize[leaderA] += groupSize[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        groupSize[leaderB] += groupSize[leaderA];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    makeSet(n);
    bool cycle = false;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB)
        {
            cycle = true;
        }
        else
        {
            unionBySize(a, b);
        }
    }
    if (cycle)
    {
        cout << "Cycle Detected!" << endl;
    }
    else
    {
        cout << "Cycle has not Detected." << endl;
    }

    return 0;
}
