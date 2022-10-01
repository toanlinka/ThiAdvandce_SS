#include <iostream>
#define NMAX 100

int main(){
	int a[NMAX+1][NMAX+1];
	int n, m, u, v;
	 
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=n; j++)
	        a[i][j]=0; 
	 
	for (int i=1; i<=m; i++)
	{
	    cin >> u >> v;
	    a[u][v]=1;
	    a[v][u]=1;
	}
	
	return 0;
}
