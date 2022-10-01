#include <bits/stdc++.h>
using namespace std;

int n,m,s,u,v;
int Free[1001];
int a[1001][1001];
queue <int> q;
int test,temp;

int BFS(int s){
	int sl =0;
	q.push(s);
	Free[s]=1;
	
	while(!q.empty()){
		u = q.front();
		q.pop();
		sl++;
		for(int v=1;v<=n;v++){
			if(Free[v]==0 && a[u][v]==1){
				Free[v]=1;
				q.push(v);
			}	
		}
	}
	return sl;
}

int main(){
	int max =0;
	cin>>test;
	for(int i=0; i<test;i++){
		cin>>n>>m;
		
		for(int i =1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=0;
			}
			Free[i]=0;
		}
		
		for(int i=1;i<=m;i++){
			cin>>u>>v;
			a[u][v]=1;
			a[v][u]=1;	
		}
		
		for (int i=1;i<=n;i++){
			if(Free[i]==0){
				temp = BFS(i);
				if(max<=temp){
					max = temp;
				}
				
			}
		}
		cout<<max;
	}
	
	return 0;
}
