#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[20][20];
bool vis[20][20];
int level[20][20];
vector<pair<int, int>> val = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    level[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first, b = par.second;
        cout << a << " " << b << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = a + val[i].first;
            int cj = b + val[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[a][b] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);

    return 0;
}
