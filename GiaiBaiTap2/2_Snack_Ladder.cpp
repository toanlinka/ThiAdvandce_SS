#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <queue>


using namespace std;
int n, m;
bool visited[101];
int f[101];
void solve(int s)
{
    int moves = 0;
    queue<int> q;
    memset(visited, false, sizeof(visited));
    int d[101];
    memset(d, 0, sizeof(d));
    
    
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            if (u + i == 100)
            {
                cout <<  d[u] + 1 << endl;
                return;
            }
            if (u + i < 100 && !visited[u + i])
            {
                int v = u + i;
                while (f[v]!=0 && !visited[v])
                {
                    visited[v] = 1;
                    v = f[v];
                    if (v == 100)
                    {
                        cout <<  d[u] + 1 << endl;
                        return;
                    }
                }
                if (visited[v]) continue;
                visited[v] = true;
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++)
    {
        int u, v; cin >> u >> v;
        f[u] = v;
    }
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        f[u] = v;
    }
    solve(1);
    
}
