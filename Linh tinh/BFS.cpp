#include <bits/stdc++.h>
using namespace std;
 
int a[101][101];
queue <int> q;
 
int n,m,Free[101], u,v,s;
 
void BFS(int s)
{
     q.push(s);
     Free[s]=0;
     while (!q.empty())
     {
        int u = q.front();
        q.pop();
 
        cout << u << endl;
 
        for (int v=1; v<=n; v++)
            if (Free[v] && a[u][v]==1)
            {
                Free[v] = 0;
                q.push(v);
            }
     }
}
 
int main()
{
 cout<<"Nhap dinh, canh, first: ";
 cin >> n >> m>> s;
 for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            a[i][j]=0;
 
 for (int i=1; i<=m; i++)
    {
    	cout<<"Nhap canh: "<<endl;
        cin >> u>> v;
        a[u][v]=1;
        a[v][u]=1;
    }
 
for (int i=1; i<=n; i++)
    Free[i]=1;

BFS(s);

 return 0;
}
